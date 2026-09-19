#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ll X,Y,Z; string S; cin >> X >> Y >> Z >> S;
    int N = (int)S.size();
    // 状態としてCapsLockがON or OFFの2種類がある
    vector<vector<ll>> dp(N,vector<ll>(2,INF));
    for(int i = 0; i < N; i++){
        if(i == 0){
            if(S[i] == 'a'){
                dp[i][0] = X;
                dp[i][1] = Y+Z;
            }
            else{
                dp[i][0] = Y;
                dp[i][1] = Z+X;
            }
            continue;
        }
        if(S[i] == 'a'){
            dp[i][0] = min(dp[i-1][1]+X+Z,dp[i-1][0]+X);
            dp[i][0] = min(dp[i-1][1]+Y+Z,dp[i][0]);

            dp[i][1] = min(dp[i-1][1]+Y,dp[i-1][0]+X+Z);
            dp[i][1] = min(dp[i-1][0]+Y+Z,dp[i][1]);
        }
        else {
            dp[i][0] = min(dp[i-1][1]+X+Z,dp[i-1][0]+Y);
            dp[i][0] = min(dp[i-1][1]+Y+Z,dp[i][0]);

            dp[i][1] = min(dp[i-1][1]+X,dp[i-1][0]+X+Z);
            dp[i][1] = min(dp[i-1][0]+Y+Z,dp[i][1]);
        }
    }
    cout << min(dp[N-1][0],dp[N-1][1]) << endl;
}
