#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    vector<ll> W(N),V(N);
    for(int i = 0; i < N; i++){
        cin >> W[i] >> V[i];
    }
    vector<vector<ll>> dp(N,vector<ll>(M+1,-1));
    for(int i = 0; i < N; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i < N; i++){
        if(i == 0){
            dp[i][W[i]] = V[i];
        }
        else {
            for(int j = 0; j <= M; j++){
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
                if(dp[i-1][j] < 0) continue;
                if(j + W[i] > M) continue;

                dp[i][j+W[i]] = max(dp[i][j+W[i]],dp[i-1][j]+V[i]);
            }
        }
    }
    // dpの復元
    vector<int> wei;    // ありうる重さ
    ll MAX = 0;
    for(int j = 0; j <= M; j++){
        MAX = max(MAX,dp[N-1][j]);
    }
    for(int j = 0; j <= M; j++){
        if(dp[N-1][j] == MAX) wei.push_back(j);
    }
    set<int> ans;    // 答えとなるiの集合
    set<pair<ll,ll>> st;
    for(int m : wei){
        st.insert({MAX,m});
    }
    for(int i = N-2; i >= 0; i--){
        bool ok = false;
        for(int j = 0; j <= M; j++){
            if(dp[i][j] < 0) continue;

            if(st.count({dp[i][j]+V[i+1],j+W[i+1]})){
                st.insert({dp[i][j],j});
                ok = true;
            }
        }
        if(ok) ans.insert(i+1);
    }
    bool ok = false;
    if(st.count({V[0],W[0]})){
        ok = true;
    }
    if(ok) ans.insert(0);
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j <= M; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = 0; i < N; i++){
        if(ans.count(i)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
