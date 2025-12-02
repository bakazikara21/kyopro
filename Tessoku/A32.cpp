#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,A,B;
    cin >> N >> A >> B;
    if(A > B) swap(A,B);

    vector<bool> dp(N+1);
    dp[0] = false;
    for(int i = 1; i <= N; i++){
        if(i < A){
            dp[i] = false;
        }else if(i < B){
            if(dp[i-A] == true){
                dp[i] = false;
            }else{
                dp[i] = true;
            }
        }else{
            if(dp[i-A] == false or dp[i-B] == false){
                dp[i] = true;
            }else{
                dp[i] = false;
            }
        }
    }
    if(dp[N] == true){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }
}
