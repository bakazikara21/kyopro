#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N-1),B(N-1);
    for(int i = 0; i < N-1; i++) cin >> A[i];
    for(int i = 0; i < N-1; i++) cin >> B[i];

    vector<int> dp(N);
    dp[0] = 0;
    for(int i = 0; i < N-1; i++){
        int a = A[i];   a--;
        int b = B[i];   b--;
        if(i == 0 or dp[i] > 0) dp[a] = max(dp[a],dp[i]+100);
        if(i == 0 or dp[i] > 0) dp[b] = max(dp[b],dp[i]+150);
    }
    cout << dp[N-1] << endl;
}
