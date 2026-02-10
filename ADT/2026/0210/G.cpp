#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    string T;
    int N;
    cin >> T >> N;
    int M = (int)T.size();
    vector<vector<int>> dp(N,vector<int>(M,inf));
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        for(int j = 0; j < A; j++){
            string S;
            cin >> S;

            int sizS = (int)S.size();
            if(i == 0){
                bool ok = true;
                for(int k = 0; k < sizS; k++){
                    if(k >= M){
                        ok = false;
                        break;
                    }
                    if(T[k] != S[k]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    dp[i][sizS-1] = 1;
                }
            }
            else {
                for(int start = 0; start <= M-sizS; start++){
                    // start文字目から start+sizS までがTと一致しているか
                    if(start > 0 and dp[i-1][start-1]==inf){
                        dp[i][start+sizS-1] = min(dp[i][start+sizS-1],dp[i-1][start+sizS-1]);
                        continue;
                    }
                    bool ok = true;
                    for(int k = 0; k < sizS; k++){
                        if(T[start+k] != S[k]){
                            ok = false;
                            break;
                        }
                    }
                    if(ok and start > 0){
                        dp[i][start+sizS-1] = dp[i-1][start-1] +1;
                    }
                    else if(ok){
                        dp[i][start+sizS-1] = 1;
                    }
                }
                for(int k = 0; k < M; k++){
                    dp[i][k] = min(dp[i][k],dp[i-1][k]);
                }
            }
        }
    }
    if(dp[N-1][M-1] == inf){
        cout << -1 << endl;
    }
    else cout << dp[N-1][M-1] << endl;

    /*
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
}
