#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
Aを後ろから以下のように処理したい。
Aiに対して、A(i+1)以降で、Ai-D <= Aj <= Ai+Dとなる
jにおいて、ans[i] = ans[j]+1みたいなことをしたい
ans[N-1] = 0;
*/
class SegRMQ{
    // セグメント木RMQ 1-indexed
    public:
        vector<ll> seg;
        int n;

        SegRMQ(int N) : seg(2*N){
            for(int i = 0; i < 2*N; i++){
                seg[i] = 0;
            }
            n = N;
        }

        void update(int pos, ll x){
            // updateは0-indexedのposを受け取る
            pos += n;
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
    // dp + segtree
    // dp[A[i]] = max{dp[k]} + 1;
    // Ai-D <= k <= Ai+D
    int N,D;
    cin >> N >> D;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    int Amax = (int)5e5 + 1;
    int n = init(Amax);
    SegRMQ segDP(n);
    for(int i = 0; i < N; i++){
        ll dpmax = segDP.segMax(max(A[i]-D,1),min(A[i]+D+1,Amax),1,0,n+1);
        segDP.update(A[i],dpmax+1);
    }
    ll ans = segDP.segMax(1,Amax,1,0,n+1);
    cout << ans << endl;
}
