#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    vector<vector<pair<int,ll>>> graph(N);
    for(int i = 0; i < M; i++){
        int u,v; ll w; cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    vector<vector<ll>> dp((1<<N),vector<ll>(N,INF));
    int mx = (1<<N);
    dp[1][0] = 0;
    for(int mask = 1; mask < mx; mask++){
        for(int v = 0; v < N; v++){
            // dp[mask][v]から移動する
            if(dp[mask][v] == INF) continue;
            for(auto [nv,cost] : graph[v]){
                //if((mask&(1<<nv)) > 0) continue;
                int nmask = mask | (1<<nv);
                dp[nmask][nv] = min(dp[nmask][nv],dp[mask][v]+cost);
            }
        }
    }
    vector<ll> distZERO(N,INF);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto [w,v] = pq.top(); pq.pop();
        if(distZERO[v] < INF) continue;
        distZERO[v] = w;
        for(auto [nv,cost] : graph[v]){
            if(distZERO[nv] < INF) continue;
            pq.push({w+cost,nv});
        }
    }
    ll ans = dp[(1<<N)-1][0];
    for(int i = 1; i < N; i++){
        if(dp[(1<<N)-1][i] == INF or distZERO[i] == INF) continue;
        ans = min(ans,dp[(1<<N)-1][i]+distZERO[i]);
    }
    if(ans < INF) cout << ans << endl;
    else cout << -1 << endl;
}
