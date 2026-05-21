#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;

int main(){
    ll K; cin >> K;
    if((K%9) != 0){
        cout << 0 << endl;
        return 0;
    }
    // dp[i] := 各桁の和がiとなる場合の数 % mod
    // dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 4, dp[4] = 8, ...
    vector<ll> dp(K+5);
    dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 4; dp[4] = 8;
    for(int k = 5; k <= K; k++){
        ll sum = 0;
        for(int j = 1; j <= 9; j++){
            if(k-j < 0) break;
            sum += dp[k-j]; // 最上位桁がjのときdp[k-j]とおり存在する
            sum %= mod;
        }
        dp[k] = sum + (k <= 9); // 1桁で実現できる場合のみインクリメント
        dp[k] %= mod;
    }
    cout << dp[K] << endl;
}