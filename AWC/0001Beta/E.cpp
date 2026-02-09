#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

class segtreeMin{
    // セグメント木RMQ 区間最大
    public:
        vector<ll> seg;
        int n;

        segtreeMin(int N) : seg(2*N){
            for(int i = 0; i < 2*N; i++){
                seg[i] = 0;
            }
            n = N;
        }

        void update(int pos, ll x){
            pos += n-1; // 1-indexed
            seg[pos] = x;
            while(pos > 1){
                // 上層部の最大値区間を更新する
                pos /= 2;
                // seg[pos]が更新されなかったらbreakでもよいと思う
                seg[pos] = min(seg[pos*2],seg[pos*2 + 1]);
            }
        }

        ll segMin(int left, int right, int pos, int first, int last){
            // [left,right)に注意する
            if(right <= first or left >= last) return (ll)1e18;
            if(left <= first and last <= right) return seg[pos];

            int mid = (first+last)/2;
            ll AnswerL = segMin(left,right,pos*2    ,first,mid);
            ll AnswerR = segMin(left,right,pos*2 + 1,mid,last);
            return min(AnswerL,AnswerR);
        }
};
class segtreeMax{
    // セグメント木RMQ 区間最大
    public:
        vector<ll> seg;
        int n;

        segtreeMax(int N) : seg(2*N){
            for(int i = 0; i < 2*N; i++){
                seg[i] = 0;
            }
            n = N;
        }

        void update(int pos, ll x){
            pos += n-1; // 1-indexed
            seg[pos] = x;
            while(pos > 1){
                // 上層部の最大値区間を更新する
                pos /= 2;
                // seg[pos]が更新されなかったらbreakでもよいと思う
                seg[pos] = max(seg[pos*2],seg[pos*2 + 1]);
            }
        }

        ll segMax(int left, int right, int pos, int first, int last){
            // [left,right)に注意する
            if(right <= first or left >= last) return (ll)-1e18;
            if(left <= first and last <= right) return seg[pos];

            int mid = (first+last)/2;
            ll AnswerL = segMax(left,right,pos*2    ,first,mid);
            ll AnswerR = segMax(left,right,pos*2 + 1,mid,last);
            return max(AnswerL,AnswerR);
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
    int N,K;
    cin >> N >> K;
    vector<ll> H(N);
    int n = init(N);
    segtreeMax segmax(n);
    segtreeMin segmin(n);
    for(int i = 0; i < N; i++){
        cin >> H[i];
        segmax.update(i+1,H[i]);
        segmin.update(i+1,H[i]);
    }
    ll ans = 0;
    for(int i = 0; i <= N-K; i++){
        ans = max(ans,segmax.segMax(i+1,i+1+K,1,1,n+1)-segmin.segMin(i+1,i+1+K,1,1,n+1));
    }
    cout << ans << endl;
}
