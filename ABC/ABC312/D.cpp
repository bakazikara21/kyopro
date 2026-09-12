#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;

int main(){
    string S; cin >> S;
    int N = (int)S.size();

    if(N%2 == 1){
        cout << 0 << endl;
        return 0;
    }
    // O(N^2)は十分高速
    /*
        '('= +1, ')'= -1とすると、
        途中の累積和が負にならない、最後の累積和は0
        ?は +1 or -1
        dp[i][j] := 左からi文字見たとき、累積和がjになる場合の数
        = dp[i-1][j+1] + ')' or dp[i-1][j-1] + '('
    */
    vector<vector<ll>> dp(N,vector<ll>(N+1,0));
    bool ok = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(S[i] == '('){
                if(i == 0) dp[i][1] = 1;
                else if(j == 0) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j-1];
            }
            else if(S[i] == ')'){
                if(i == 0)  ok = false;
                else dp[i][j] = dp[i-1][j+1];
            }
            else if(i == 0){
                dp[i][1] = 1;
            }
            else if(j == 0){
                dp[i][0] = dp[i-1][1];
            }
            else dp[i][j] = dp[i-1][j+1] + dp[i-1][j-1];
            dp[i][j] %= mod;
        }
    }
    if(ok) cout << dp[N-1][0] << endl;
    else cout << 0 << endl;
}
