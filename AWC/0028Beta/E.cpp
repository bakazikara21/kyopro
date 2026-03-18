#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const int mod = 1000000007;
int main(){
    int N,K; cin >> N >> K;
    vector<int> A(N),P(K);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < K; i++) cin >> P[i];

    vector<ll> dp(K);
    for(int i = 0; i < N; i++){
        for(int k = K-1; k >= 0; k--){
            if(k == 0 and A[i] == P[k]){
                dp[0]++;
                dp[k] %= mod;
            }
            else if(A[i] == P[k]){
                dp[k] += dp[k-1];
                dp[k] %= mod;
            }
        }
    }
    cout << dp[K-1] << endl;
}
