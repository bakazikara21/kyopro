#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string T;
    int N;
    cin >> T >> N;
    
    int siz = (int)T.size();
    vector<vector<int>> dp(N+1,vector<int>(siz+1,1000));
    for(int i = 0; i <= N; i++){
        dp[i][0] = 0;   // 0文字目まで一致させるのは0円で行ける
    }
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        for(int j = 0; j < A; j++){
            string S;
            cin >> S;

            // こいつを選ぶとき
            int sizeS = (int)S.size();
            for(int k = 0; k <= siz - sizeS; k++){
                // T[k]~T[k+sizeS-1]まで一致するかどうかを調べる
                bool ok = true;
                for(int l = 0; l < sizeS; l++){
                    if(S[l] != T[k+l]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    if(dp[i][k] == 1000) continue;
                    dp[i+1][k+sizeS] = min(dp[i][k+sizeS],dp[i][k]+1);
                }
            }
        }
        for(int t = 1; t <= siz; t++){
            dp[i+1][t] = min(dp[i+1][t],dp[i][t]);
        }
    }
    if(dp[N][siz] == 1000){
        cout << -1 << endl;
    }
    else cout << dp[N][siz] << endl;
}