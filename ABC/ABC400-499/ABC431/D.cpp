#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;

    vector<ll> W(N),H(N),B(N);
    int hmax = 0;
    for(int i = 0; i < N; i++){
        cin >> W[i] >> H[i] >> B[i];
        hmax += W[i];
    }
    hmax = (hmax+2) / 2;
    vector<vector<ll>> dp(N+1,vector<ll>(hmax));    // i個取り付けたときの頭の重さがj以下で最大のうれしさ
    for(int j = 0; j < hmax; j++){
        dp[0][j] = 0;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < hmax; j++){
            if((j-W[i-1]) < 0){

                dp[i][j] = max(dp[i][j],dp[i-1][j]+B[i-1]);

            }else{
                //cout << i << " " << j << " " << dp[i-1][j-W[i-1]]+H[i-1] << endl;
                dp[i][j] = max(dp[i-1][j-W[i-1]]+H[i-1], dp[i-1][j]+B[i-1]);
            }
        }
    }
    ll ans = 0;
    for(int j = 0; j < hmax; j++){
        ans = max(ans,dp[N][j]);
    }
    //for(int i = 0; i <= N; i++){
    //    for(int j = 0; j < hmax; j++){
    //        cout << dp[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    cout << ans << endl;
    //cout << hmax << endl;
}