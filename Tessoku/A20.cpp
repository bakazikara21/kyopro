#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S,T;
    cin >> S >> T;

    int imax = S.size();
    int jmax = T.size();
    vector<vector<int>> dp(imax+1,vector<int>(jmax+1,0));

    for(int i = 1; i <= imax; i++){
        for(int j = 1; j <= jmax; j++){
            dp[i][j] = max(dp[i-1][j-1]+(S[i-1]==T[j-1]),max(dp[i-1][j],dp[i][j-1]));
        }
    }
    /*
    for(int i = 0; i <= imax; i++){
        for(int j = 0; j <= jmax; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    cout << dp[imax][jmax] << endl;
}
