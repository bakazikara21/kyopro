#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M,T; cin >> N >> M >> T;
    vector<ll> A(N),B(N),C(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i] >> C[i];
    }
    vector<vector<ll>> dp(N+1,vector<ll>(M+1,-INF));
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= M; j++){
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
            if(dp[i-1][j] == -INF) continue;
            if(B[i-1] >= T){
                dp[i][j] += A[i-1];
            }
            else if(j+C[i-1] <= M){
                dp[i][j+C[i-1]] = max(dp[i][j+C[i-1]],dp[i-1][j]+A[i-1]);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= M; i++){
        ans = max(ans,dp[N][i]);
    }
    cout << ans << endl;
}
