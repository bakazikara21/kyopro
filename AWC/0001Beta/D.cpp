#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M,K;
    cin >> N >> M >> K;

    vector<ll> A(N),B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }
    vector<vector<ll>> dp(N,vector<ll>(M+1,0));
    dp[0][B[0]] = A[0];
    for(int i = 1; i < N; i++){
        int start = max(0,i-K);
        for(int j = start; j < i; j++){
            for(int k = 0; k < M; k++){
                if(k > 0 and dp[j][k] == 0) continue;
                if(k+B[i] > M){
                    continue;
                }
                dp[i][k+B[i]] = max(dp[i][k+B[i]],dp[j][k]+A[i]);
                //dp[i][k+B[i]] = max(dp[i][k+B[i]],dp[j][k+B[i]]);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            //cout << dp[i][j] << " ";
            ans = max(ans,dp[i][j]);
        }
        //cout << endl;
    }
    //cout << endl;
    cout << ans << endl;
}
