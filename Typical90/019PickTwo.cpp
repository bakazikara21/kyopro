#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<int> A(2*N);
    for(int i = 0; i < 2*N; i++) cin >> A[i];
    /*
        区間dp[l][r] := A[l]..A[r]をすべて取り除くときの最小コスト
    */
    vector<vector<int>> dp(2*N,vector<int>(2*N,inf));
    for(int i = 0; i < 2*N-1; i++){
        dp[i][i+1] = abs(A[i]-A[i+1]);
    }
    for(int left = 0; left < 2*N; left++){
        for(int right = left+3; right < 2*N; right+=2){
            // dp[left][right] = min(dp[left][left+1]+dp[left+2][right],...);
            for(int k = left; k < right; k++){
                if(k == left) dp[left][right] = min(dp[left][right],dp[k][k+1]+dp[k+2][right]);
                else if(k == right-1) dp[left][right] = min(dp[left][right],dp[left][k-1]+dp[k][k+1]);
                else dp[left][right] = min(dp[left][right],dp[left][k-1]+dp[k][k+1]+dp[k+2][right]);
            }
        }
    }
    cout << dp[0][2*N-1] << endl;
    for(int l = 0; l < 2*N; l++){
        for(int r = l+1; r < 2*N; r+=2){
            cout << "left = " << l << " right = " << r << " dp[l][r] = " << dp[l][r] << endl;
        }
    }
}
