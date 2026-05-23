#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    auto B = A;
    reverse(B.begin(),B.end()); // 配列Aの逆順

    // dp[i] = 末尾がA[i]の増加部分列の最大の長さ
    vector<ll> dp(N);  
    vector<ll> dp2(N);  // 末尾がA[i]の減少部分列の最大の長さ

    // Lmin[x] 長さxとしてありうる増加部分列の末尾の最小値
    vector<ll> Lmin(N+1,INF);   // ->単調増加
    vector<ll> Lmin2(N+1,INF);   // 長さxとしてありうる増加部分列の末尾の最小値
    Lmin[0] = 0;    
    Lmin2[0] = 0;
    for(int i = 0; i < N; i++){
        if(i == 0){
            dp[i] = 1;
            dp2[i] = 1;
            Lmin[1] = A[i];
            Lmin2[1] = B[i];
        } 
        else {
            // 末尾がA[i]未満で最大の長さの列の末尾にA[i]を追加することを考える
            // t = 末尾がA[i]以上である中で最小の文字列の長さ
            int t = lower_bound(Lmin.begin(),Lmin.end(),A[i])-Lmin.begin();
            dp[i] = t;
            Lmin[t] = min(Lmin[t],A[i]);

            // 末尾がB[i]未満で最大の長さの列の末尾にB[i]を追加することを考える
            // t = 末尾がB[i]以上である中で最小の文字列の長さ
            int t2 = lower_bound(Lmin2.begin(),Lmin2.end(),B[i])-Lmin2.begin();
            dp2[i] = t2;
            Lmin2[t2] = min(Lmin2[t2],B[i]);
        }
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans = max(ans,dp[i]+dp2[N-1-i]-1);
    }
    cout << ans << endl;
}