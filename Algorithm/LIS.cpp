#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
// 最長増加部分列LISを求める
int main(){
    int N;
    cin >> N;

    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    // dp[i] = 末尾がA[i]の増加部分列の最大の長さ
    vector<ll> dp(N);  

    // Lmin[x] 長さxとしてありうる増加部分列の末尾の最小値
    vector<ll> Lmin(N+1,INF);   // ->単調増加
    Lmin[0] = 0;    
    for(int i = 0; i < N; i++){
        if(i == 0){
            dp[i] = 1;
            Lmin[1] = A[i];
        } 
        else {
            // 末尾がA[i]未満で最大の長さの列の末尾
            // t = 末尾がA[i]以上である中で最小の文字列の長さ
            int t = lower_bound(Lmin.begin(),Lmin.end(),A[i])-Lmin.begin();
            dp[i] = t;
            Lmin[t] = min(Lmin[t],A[i]);
        }
    }
    int ans = lower_bound(Lmin.begin(),Lmin.end(),INF)-Lmin.begin();
    cout << ans-1 << endl;
}