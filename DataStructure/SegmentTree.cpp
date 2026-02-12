#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class SegRMQ{
    // セグメント木RMQ 区間最大・最小
    public:
        vector<ll> segmax;
        vector<ll> segmin;
        int n;

        SegRMQ(int N){
            int siz = 1;
            while(siz < N){
                siz *= 2;
            }
            n = siz;
            segmax.resize(2*n);
            segmin.resize(2*n);
            for(int i = 0; i < 2*n; i++){
                segmax[i] = 0;
                segmin[i] = 0;
            }
        }

        void update(int pos, ll x){
            pos += n-1; // 1-indexed
            segmax[pos] = x;
            segmin[pos] = x;
            while(pos > 1){
                // 上層部の最大値区間を更新する
                pos /= 2;
                // segmax[pos]が更新されなかったらbreakでもよいと思う
                segmax[pos] = max(segmax[pos*2],segmax[pos*2 + 1]);
                segmin[pos] = min(segmin[pos*2],segmin[pos*2 + 1]);
            }
        }

        ll get_segmax(int left, int right, int pos, int first, int last){
            // [left,right)に注意する
            if(right <= first or left >= last) return (ll)-1e18;
            if(left <= first and last <= right) return segmax[pos];

            int mid = (first+last)/2;
            ll AnswerL = get_segmax(left,right,pos*2    ,first,mid);
            ll AnswerR = get_segmax(left,right,pos*2 + 1,mid,last);
            return max(AnswerL,AnswerR);
        }
        ll get_segmin(int left, int right, int pos, int first, int last){
            // [left,right)に注意する
            if(right <= first or left >= last) return (ll)1e18;
            if(left <= first and last <= right) return segmin[pos];

            int mid = (first+last)/2;
            ll AnswerL = get_segmin(left,right,pos*2    ,first,mid);
            ll AnswerR = get_segmin(left,right,pos*2 + 1,mid,last);
            return min(AnswerL,AnswerR);
        }
};

class SegRSQ{
    // セグメント木RSQ 区間和
    public:
        vector<ll> seg;
        int n;

        SegRSQ(int N) : seg(2*N){
            for(int i = 0; i < 2*N; i++){
                seg[i] = 0;
            }
            n = N;
        }

        void update(int pos, ll x){
            pos += n-1; // 1-indexed
            seg[pos] = x;
            while(pos > 1){
                // 上層部の区間和を更新する
                pos /= 2;
                // seg[pos]が更新されなかったらbreakでもよいと思う
                seg[pos] = seg[pos*2] + seg[pos*2+1];
            }
        }

        void add(int pos, ll x){
            // segに差分配列を持たせると区間加算が実現できる
            // 区間加算を行うとき、加算による更新が必要
            pos += n-1; // 1-indexed
            seg[pos] += x;
            while(pos > 1){
                // 上層部の区間和を更新する
                pos /= 2;
                // seg[pos]が更新されなかったらbreakでもよいと思う
                seg[pos] = seg[pos*2] + seg[pos*2+1];
            }
        }

        ll segSum(int left, int right, int pos, int first, int last){
            // [left,right)に注意する
            if(right <= first or left >= last) return 0;
            if(left <= first and last <= right) return seg[pos];

            int mid = (first+last)/2;
            ll AnswerL = segSum(left,right,pos*2    ,first,mid);
            ll AnswerR = segSum(left,right,pos*2 + 1,mid,last);
            return AnswerL+AnswerR;
        }
};

int init(int N){
    int siz = 1;
    while(siz < N){
        siz *= 2;
    }
    return siz;
}