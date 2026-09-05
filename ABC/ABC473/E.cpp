#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K; cin >> N >> K;
    vector<ll> A(N);
    for(ll &a : A) cin >> a;
    // 配列Aをいくつかに分割して
    // 各分割の和のなかで = Kの倍数となる個数の最大値を求める
    // dp[k+1] = dp[t-1] + 1; sum[k+1] === sum[t-1] (mod.K)
    vector<ll> sum(N+1);
    vector<int> dp(N);
    map<int,int> mxID;  // あまりが j となる暫定で最大の添え字
    for(int i = 0; i < N; i++){
        sum[i+1] += sum[i] + A[i];
    }
    mxID[0] = 0;
    for(int left = 0; left < N; left++){
        // dp[left] = A[0] ~ A[left]までのスコアの最大値
        if(left > 0) dp[left] = dp[left-1];

        int r = sum[left+1]%K;

        if(mxID.count(r)){
            // あまりが等しい累積和が存在するとき、
            int id = mxID[r];
       
            dp[left] = max(dp[id] + 1, dp[left-1]); 
        }
        else if(A[left]%K == 0){
            if(left > 0) dp[left] = dp[left-1] + 1;
            else dp[left] = 1;
        }
        mxID[r] = left;
    }
    cout << dp[N-1] << endl;
}
