#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e15;
// Product Development
int main(){
    int N,K,P;
    cin >> N >> K >> P;

    vector<vector<int>> A(N,vector<int>(K));
    vector<ll> C(N);
    for(int i = 0; i < N; i++){
        cin >> C[i];
        for(int j = 0; j < K; j++){
            // j個目のパラメータがA[i][j]増加する
            cin >> A[i][j];
        }
    }
    int jmax = pow(P+1,K); // P,P,P,P,P以降は数える必要ない
    vector<vector<ll>> dp(N,vector<ll>(jmax,INF));
    
    for(int i = 0; i < N; i++){
        // i番目の開発案までで最小のコストを求める
        for(int j = 0; j < jmax; j++){
            // i個目までの開発案を考慮したときに存在しうるパラメータの値
            // 各桁の値numを求める。K桁あります。
            int tmp = j;
            vector<int> num(K),next(K);
            for(int k = 0; k < K; k++){
                // 右からkビット目がj%P+1
                num[k] = (tmp%(P+1));
                tmp /= P+1;

                // 上記のnumにA[i][0]~A[i][K-1]をそれぞれ足す。min(A+num,P);
                next[k] = min(A[i][k]+num[k],P);
            }   
            
            // 続いて、next[k]を整数に直します。
            ll id = 0;
            ll pp = 1;
            for(int k = 0; k < K; k++){
                id += next[k]*pp;
                pp *= P+1;
            }

            // 上記のidにおいてdpの更新を行う

            if(j == 0){
                dp[i][j] = 0;
            }
            if(i == 0){
                dp[i][id] = C[i];
                break;
            }
            else if(dp[i-1][j] < INF){
                dp[i][id] = min(min(dp[i-1][id],dp[i][id]),dp[i-1][j]+C[i]);
            }
            dp[i][j] = min(dp[i-1][j],dp[i][j]);
        }
    }
    if(dp[N-1][jmax-1] < INF){
        cout << dp[N-1][jmax-1] << endl;
    }else{
        cout << -1 << endl;
    }
}
