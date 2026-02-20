#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

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
int init(int N){
    int siz = 1;
    while(siz < N){
        siz *= 2;
    }
    return siz;
}
int main(){
    int N,Q;
    cin >> N >> Q;
    int n = init(N);
    SegRMQ segtree(n);
    for(int i = 0; i < N; i++){
        ll A; cin >> A;
        segtree.update(i+1,A);
    }
    for(int q = 0; q < Q; q++){
        int L,R;
        cin >> L >> R;
        ll maxi = segtree.get_segmax(L,R+1,1,1,n+1);
        ll mini = segtree.get_segmin(L,R+1,1,1,n+1);
        cout << maxi - mini << endl;
    }
}
