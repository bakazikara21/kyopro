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
    for(int i = N-1; i > 0; i--){
        start = (pow(3,i)-1)/2 + 1;
        int jmax = (pow(3,i+1)-1)/2;
        for(int j = start; j <= jmax; j++){
            // dp[j][0] -> 000 001 010 100
        }
    }
}
