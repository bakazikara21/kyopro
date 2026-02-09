#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    三分木dpで解く
*/
int main(){
    int N;
    cin >> N;
    string A;
    cin >> A;
    int maximum = (int)A.size();
    int siz = (maximum*3-1)/2;
    vector<char> S(siz+1);
    vector<vector<int>> dp(siz+1,vector<int>(2));   // 下の部分木を0 or 1に必要な最小の操作回数
    
    int start = (maximum-1)/2 + 1;
    for(int i = start; i < siz+1; i++){
        S[i] = A[i-start];
        if(S[i] == '1'){
            dp[i][0] = 1;
            dp[i][1] = 0;
        }
        else{
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        //cout << S[i];
    }
    //cout << endl;
    start = (maximum-1)/2;
    for(int i = start; i > 0; i--){
        // 下の部分木は3*i-1, 3*i, 3*i+1
        // dp[j][0] -> 000 001 010 100
        dp[i][0] = dp[3*i-1][0]+dp[3*i][0]+dp[3*i+1][0];    // 000にするとき
        dp[i][0] = min(dp[i][0],dp[3*i-1][0]+dp[3*i][0]+dp[3*i+1][1]);
        dp[i][0] = min(dp[i][0],dp[3*i-1][0]+dp[3*i][1]+dp[3*i+1][0]);
        dp[i][0] = min(dp[i][0],dp[3*i-1][1]+dp[3*i][0]+dp[3*i+1][0]);

        // dp[j][1] -> 011 101 110 111
        dp[i][1] = dp[3*i-1][0]+dp[3*i][1]+dp[3*i+1][1];    // 011にするとき
        dp[i][1] = min(dp[i][1],dp[3*i-1][1]+dp[3*i][0]+dp[3*i+1][1]);
        dp[i][1] = min(dp[i][1],dp[3*i-1][1]+dp[3*i][1]+dp[3*i+1][0]);
        dp[i][1] = min(dp[i][1],dp[3*i-1][1]+dp[3*i][1]+dp[3*i+1][1]);
    }
    cout << max(dp[1][0],dp[1][1]) << endl;
}
