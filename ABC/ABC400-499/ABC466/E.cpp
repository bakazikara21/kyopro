#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K; cin >> N >> K;
    vector<ll> A(N),B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }
    /*
      diff = -2 -3 1 3 5 -2 2 2 -7 8 3 -1 2
      
      基本的にdiff > 0の連続区間をひっくり返していく
      全てのdiffが0以下になったら最適
      問題なのは(diff < 0)なるdiffを含めてひっくり返すとき
      例えば K=1 なら L=3,R=13が最適 -> +16
      
      解説：区間を2K+1個に分割する（要素が空の場所があっても良い）
      表 | 裏 | 表 | 裏 | ... | 表　と分割する
      dp[i][j]は、 i番目のカードがj番目の区間に属するときの
      カード 1,2,…,i の上を向いている面に書かれている数の和
      として考えられる最大値
    */
    ll ans = 0;
    int jmax = 2*K + 1;
    vector<vector<ll>> dp(N+1,vector<ll>(jmax+1));
    for(int i = 1; i <= N; i++){
        // i番目のカードがj番目の区間に属するとき
        // dp[i][j] := カード 1,2,…,i に書かれている数の和の最大値
        for(int j = 1; j <= jmax; j++){
            // jが偶数ならば、裏面の値を採用する
            if(j%2 == 1){
                dp[i][j] = max(dp[i-1][j-1]+A[i-1],dp[i-1][j]+A[i-1]);
            }else{
                dp[i][j] = max(dp[i-1][j-1]+B[i-1],dp[i-1][j]+B[i-1]);
            }
        }
    }
    for(int j = 1; j <= jmax; j++) ans = max(ans,dp[N][j]);
    cout << ans << endl;
}
