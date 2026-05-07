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

        隣接している要素同士でしか削除できないことから、
        dp[l][r] = min(dp[l][i]+dp[i+1][r]) (i = l+1,l+3,...,r-2)
        dp[l][r] = min(dp[l][r], dp[l+1][r-1]+abs(A[l]-A[r]))
        で求められる。最悪O(N)
        -> O(N^3)で求められる
    */
    vector<vector<int>> dp(2*N,vector<int>(2*N,inf));
    for(int i = 0; i < 2*N-1; i++){
        dp[i][i+1] = abs(A[i]-A[i+1]);
    }
    for(int width = 4; width <= 2*N; width += 2){
        for(int l = 0; l+width-1 < 2*N; l+=1){
            // 左端をA[l]として、幅widthのdp[l][l+width-1]の最小値を求める
            // dp[l][r] = min(dp[l][i]+dp[i+1][r]) (i = l+1,l+3,...,r-2)
            // dp[l][r] = min(dp[l][r], dp[l+1][r-1]+abs(A[l]-A[r]))
            for(int i = l+1; i <= l+width-3; i += 2){
                dp[l][l+width-1] = min(dp[l][l+width-1],dp[l][i]+dp[i+1][l+width-1]);
            }
            dp[l][l+width-1] = min(dp[l][l+width-1],dp[l+1][l+width-2]+abs(A[l]-A[l+width-1]));
        }
    }
    cout << dp[0][2*N-1] << endl;
    // for(int l = 0; l < 2*N; l++){
    //     for(int r = l+1; r < 2*N; r+=2){
    //         cout << "left = " << l << " right = " << r << " dp[l][r] = " << dp[l][r] << endl;
    //     }
    // }
}
