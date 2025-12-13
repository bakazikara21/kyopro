#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;

    vector<int> A(N),dp(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    dp[0] = -1;
    for(int i = 1; i < N; i++){
        if(A[i-1] > A[i]){
            dp[i] = i-1;
        }else if(dp[i-1] == -1){
            dp[i] = -1;
        }else{
            int x = dp[i-1];
            while(x != -1 and A[x] <= A[i]){
                x = dp[x];
            }
            if(x == -1) dp[i] = -1;
            else dp[i] = x;
        }
    }
    for(int i = 0; i < N; i++){
        if(dp[i] == -1) cout << dp[i] << " ";
        else cout << dp[i]+1 << " ";
    }
    cout << endl;
}
