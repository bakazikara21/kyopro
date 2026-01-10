#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Doubling Tessoku-A57
int main(){
    int N,Q;
    cin >> N >> Q;

    vector<ll> A(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    // dp[i][j] = 穴jの2^i日後のあな
    vector<vector<int>> dp(30,vector<int>(N+1));    
    for(int i = 0; i < 30; i++){
        for(int j = 1; j <= N; j++){
            if(i == 0){
                dp[i][j] = A[j];
            }else{
                dp[i][j] = dp[i-1][dp[i-1][j]];
            }
        }
    }

    for(int q = 0; q < Q; q++){
        int X,Y;
        cin >> X >> Y;

        int i = 0;
        while(Y > 0){
            if(Y%2 == 1) X = dp[i][X];
            i++;
            Y /= 2;
        }
        cout << X << endl;
    }
}