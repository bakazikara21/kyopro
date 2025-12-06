#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<vector<int>> dp(N,vector<int>(N));
    for(int j = 0; j < N; j++){
        dp[N-1][j] = A[j];
    }
    for(int i = N-2; i >= 0; i--){
        if(i%2 == 0){
            for(int j = 0; j <= i; j++){
                dp[i][j] = dp[i+1][j];
                dp[i][j] = max(dp[i][j],dp[i+1][j+1]);
            }
        }else{
            for(int j = 0; j < N; j++){
                dp[i][j] = dp[i+1][j];
                dp[i][j] = min(dp[i][j],dp[i+1][j+1]);
            }
        }
    }
    cout << dp[0][0] << endl;
}
