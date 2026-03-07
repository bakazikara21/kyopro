#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K,B; cin >> N >> K >> B;
    /*
        dp[i+1][c] := 
        (最後に高さS[i]の山に登った時に
        コストcで登れる山頂の数の最大値)
    */
    vector<vector<int>> dp(N+1,vector<int>(B+1,-1));
    dp[0][0] = 0;
    int ans = 1;
    vector<int> C(N),S(N);
    for(int i = 0; i < N; i++){
        cin >> C[i] >> S[i];
        dp[i+1][C[i]] = 1;
        for(int j = 0; j < i; j++){
            if(S[j] >= S[i]) continue;
            for(int c = 0; c < B; c++){
                if(dp[j+1][c] < 0) continue;
                if(c+C[i] > B) continue;
                dp[i+1][c+C[i]] = max(dp[i+1][c+C[i]],dp[j+1][c] + 1);
                ans = max(ans,dp[i+1][c+C[i]]);
            }
        }
    }
    cout << min(ans,K) << endl;
}
