#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)inf+7;

int main(){
    int N,S; cin >> N >> S;
    vector<int> A(N),B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    vector<vector<int>> dp(N+1,vector<int>(S+1,-1));
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++){
        // Aを選んだら1, Bを選んだら2
        for(int s = 0; s <= S; s++){
            if(dp[i-1][s] >= 0){
                if(s+A[i-1] <= S) dp[i][s+A[i-1]] = 1;
                if(s+B[i-1] <= S and dp[i][s+B[i-1]] == -1) dp[i][s+B[i-1]] = 2;
            }
        }
    }
    if(dp[N][S] >= 1){
        int s = S;
        string ans = "";
        for(int n = N; n >= 1; n--){
            if(dp[n][s] == 1){
                ans += 'A';
                s -= A[n-1];
            }
            else if(dp[n][s] == 2){
                ans += 'B';
                s -= B[n-1];
            }
        }
        reverse(ans.begin(),ans.end());
        cout << ans << endl;
    }
    else{
        cout << "Impossible" << endl;
    }
}