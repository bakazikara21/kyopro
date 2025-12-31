#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> A(K);
    for(int i = 0; i < K; i++){
        cin >> A[i];
    }
    
    vector<ll> dif(K-1),dp(K);
    for(int i = 0; i < K-1; i++){
        dif[i] = A[i+1]-A[i];
        if(i < 2) dp[i+1] = dif[i];
        else if(i%2 == 0) dp[i+1] = dp[i-1]+dif[i];
    }
    for(int i = 4; i < K; i += 2){
        dp[i] = min(dp[i-2]+dif[i-1],dp[i-3]+dif[i-1]);
    }
    if(K%2 == 1 and K >= 3){
        // dpで解けることにだいぶ時間かかった->緑diff
        cout << min(dp[K-1],dp[K-2]) << endl;
    }else{
        cout << dp[K-1] << endl;
    }
    /*
    for(int i = 0; i < K; i++){
        cout << "dp[" << i << "] = " << dp[i] << endl;
    }
    */
}
