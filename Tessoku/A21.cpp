#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;

    vector<int> P(N),A(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i] >> A[i];
    }
    vector<vector<int>> dp(N+1,vector<int>(N+1));
    dp[0][0] = 0;   // 左からi個、右からj個のブロックを取り除いたときの得点の最大値
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(i == 0 and j == 0) continue;
            if(i + j  > N) continue;

            if(i == 0){
                int pj = 0; // j番目を取り除いたときの追加される得点
                if(P[N-j] > i and P[N-j] < N-j+1){
                    pj += A[N-j];
                }
                dp[i][j] = dp[i][j-1]+pj;
            }else if(j == 0){
                int pi = 0; // i番目を取り除いたときの追加される得点
                if(P[i-1] < N-j+1 and P[i-1] > i){
                    pi += A[i-1];
                }
                dp[i][j] = dp[i-1][j]+pi;
            }else{
                int pj = 0; // j番目を取り除いたときの追加される得点
                if(P[N-j] > i and P[N-j] < N-j+1){
                    pj += A[N-j];
                }
                int pi = 0; // i番目を取り除いたときの追加される得点
                if(P[i-1] < N-j+1 and P[i-1] > i){
                    pi += A[i-1];
                }
                dp[i][j] = max(dp[i][j-1]+pj,dp[i-1][j]+pi);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(i+j > N) continue;
            ans = max(ans,dp[i][j]);
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    cout << ans << endl;
}
