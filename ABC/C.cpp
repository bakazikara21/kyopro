#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class SegRMQ{
    // セグメント木RMQ
    public:
        vector<ll> seg;

        SegRMQ(int N) : seg(2*N){
            for(int i = 0; i < 2*N; i++){
                seg[i] = 0;
            }
        }

        void update(int pos, ll x){
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
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];

    vector<ll> ruisekiA(N+1),ruisekiB(N+1),ruisekiC(N+1);
    for(int i = 0; i < N; i++){
        ruisekiA[i+1] = ruisekiA[i]+A[i];
        ruisekiB[i+1] = ruisekiB[i]+B[i];
        ruisekiC[i+1] = ruisekiC[i]+C[i];
    }

    int n = init(N);
    SegRMQ seg(n);
    for(int y = 0; y < N; y++){
        seg.update(y+n,ruisekiB[y+1]-ruisekiC[y+1]);
    }
    ll ans = 0;
    for(int x = 0; x < N-2; x++){
        // xを固定して、区間の最大yを高速に求めればよい
        ll maxi = seg.segMax(x+2,N,1,1,n+1);
        maxi += ruisekiC[N]+ruisekiA[x+1]-ruisekiB[x+1];
        ans = max(ans,maxi);
    }
    cout << ans << endl;
}
