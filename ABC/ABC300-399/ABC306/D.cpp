#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<vector<ll>> dp(N+1,vector<ll>(2));
    for(int i = 0; i < N; i++){
        dp[i+1][0] = dp[i][0];  // 健康
        dp[i+1][1] = dp[i][1];  // 毒状態
        int x,y; cin >> x >> y;
        if(x == 1){
            dp[i+1][1] = max(dp[i+1][1],dp[i][0]+y);
        }
        else{
            dp[i+1][0] = max(dp[i+1][0],dp[i][1]+y);
            dp[i+1][0] = max(dp[i+1][0],dp[i][0]+y);
        }
    }
    cout << max(dp[N][0],dp[N][1]) << endl;
}
