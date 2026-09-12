#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    const int MAX = 3000;
    int N,H,M;
    cin >> N >> H >> M;
    vector<int> A(N),B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    vector<vector<int>> dp(N+1,vector<int>(M+1,-1));
    dp[0][M] = H;
    /*
        dp[i][m] := (i体目までのモンスターを倒したときに、魔法がmであるときの体力hの最大値)
    */
    for(int i = 1; i <= N; i++){
        for(int m = 0; m <= M; m++){
            if(dp[i-1][m] < 0) continue;
            // dp[i-1][m]から配るdp
            int mB = m - B[i-1];
            int hA = dp[i-1][m] - A[i-1];
            if(mB >= 0 and hA >= 0){
                dp[i][mB] = max(dp[i][mB],dp[i-1][m]);
                dp[i][m] = max(dp[i][m],hA);
            }
            else if(mB >= 0) dp[i][mB] = max(dp[i][mB],dp[i-1][m]);
            else if(hA >= 0) dp[i][m] = max(dp[i][m],hA);
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(dp[i][j] >= 0){
                ans = i;
            }
        }
    }
    cout << ans << endl;
}
