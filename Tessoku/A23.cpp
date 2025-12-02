#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = (int)1e9;
int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> A(M,vector<int>(N));
    vector<int> binary(M);
    for(int i = 0; i < M; i++){
        int sum = 0;
        int two = 1;
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
            sum += A[i][j]*two;
            two *= 2;
        }
        binary[i] = sum;
    }
    int jmax = 1<<N;
    // i枚目までのクーポンで2進数表現の集合jを無料で引き換えることのできる最小のクーポンの枚数
    vector<vector<int>> dp(M+1,vector<int>(jmax,inf));
    dp[0][0] = 0;
    for(int i = 1; i <= M; i++){
        for(int j = 0; j < jmax; j++){
            if(j == 0){
                dp[i][j] = 0;
            }
            if(dp[i-1][j] < inf){
                dp[i][j|binary[i-1]] = min(dp[i][j|binary[i-1]],dp[i-1][j]+1);
                dp[i][j] = min(dp[i-1][j],dp[i][j]);
            }
        }
    }
    /*
    for(int i = 0; i <= M; i++){
        for(int j = 0; j < jmax; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    if(dp[M][jmax-1] == inf){
        cout << -1 << endl;
    }else{
        cout << dp[M][jmax-1] << endl;
    }
}
