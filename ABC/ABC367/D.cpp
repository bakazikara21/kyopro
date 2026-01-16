#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e9;
/*
presum[s] == presum[t] (mod.M)
かつ
s+1 <= t <= s+N-1
となる(s,t)の組の個数を数えればよい
-> 逐次差分更新区間累積和
*/
int main(){
    int N,M;
    cin >> N >> M;
    vector<ll> A(N),presum(2*N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        presum[i+1] = presum[i]+A[i];
    }
    for(int i = 1; i < N-1; i++){
        presum[N+i] = presum[N+i-1]+A[i-1];
    }
    vector<ll> mod(M);
    for(int i = 0; i < N; i++){
        ll mo = presum[i]%M;
        mod[mo]++;
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        // 逐次差分更新区間累積和
        ll mo = presum[i]%M;
        mod[mo]--;
        ans += mod[mo];
        mo = presum[i+N]%M;
        mod[mo]++;
    }
    cout << ans << endl;
}