#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int zmax = (int)1e5;
const ll inf = (ll)1e18;
int main(){
    int N;
    cin >> N;

    vector<ll> X(N),Y(N),Z(N);

    // i番目の選挙区までで、j議席を奪うのに必要な鞍替え人数
    vector<vector<ll>> dp(N,vector<ll>(zmax+1,inf));
    ll takahashi = 0;
    ll aoki = 0;
    for(int i = 0; i < N; i++){
        cin >> X[i] >> Y[i] >> Z[i];
        if(X[i] > Y[i]){
            takahashi += Z[i];
        }else{
            aoki += Z[i];
        }
        dp[i][0] = 0;   // 初期化
    }

    for(int i = 0; i < N; i++){
        ll x = X[i];
        ll y = Y[i];
        ll z = Z[i];
        ll need = (y-x+1)/2;    // z議席を奪うのに必要な鞍替え人数
        //cout << "i = " << i << " z = " << z << " need = " << need << endl;
        if(i == 0){
            if(need > 0){
                dp[i][z] = need;
                //cout << "i = " << i << " z = " << z << " need = " << need << endl;
            }
            continue;
        }
        for(int k = 0; k <= zmax; k++){
            if(dp[i-1][k] < inf and z+k <= zmax and need > 0){
                dp[i][z+k] = min(dp[i-1][k]+need,dp[i-1][z+k]);
            }
            dp[i][k] = min(dp[i][k],dp[i-1][k]);
        }
    }
    ll need = (aoki-takahashi+1)/2;    // たかはしが追加で必要な議席数
    if(need <= 0){
        cout << 0 << endl;
    }else{
        ll ans = inf;
        for(int i = need; i <= zmax; i++){
            ans = min(ans,dp[N-1][i]);
        }
        cout << ans << endl;
    }
    /*
    for(int i = 0; i < N; i++){
        for(int k = 0; k <= 10; k++){
            cout << dp[i][k] << " ";
        }
        cout << endl;
    }
        https://atcoder.jp/contests/abc317/tasks/abc317_d
    */
}