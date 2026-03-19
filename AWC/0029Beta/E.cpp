#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    vector<vector<pair<int,ll>>> graph(N);
    for(int i = 0; i < M; i++){
        int u,v,w; cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back({v,w});
    }
    int S,K; cin >> S >> K; S--;
    vector<int> T(K);
    for(int i = 0; i < K; i++) cin >> T[i],T[i]--;
    vector<vector<ll>> dist(K,vector<ll>(N,INF));
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    for(int k = 0; k < K; k++){
        // T[k]からの最小コスト
        int s = T[k];
        pq.push({0,s});
        while(!pq.empty()){
            auto [d,v] = pq.top(); pq.pop();
            if(dist[k][v] < INF) continue;
            dist[k][v] = d;
            for(auto [nv,cost] : graph[v]){
                if(dist[k][nv] < INF) continue;
                pq.push({d+cost,nv});
            }
        }
    }
    vector<ll> dis(N,INF);
    pq.push({0,S});
    while(!pq.empty()){
        auto [d,v] = pq.top(); pq.pop();
        if(dis[v] < INF) continue;
        dis[v] = d;
        for(auto [nv,cost] : graph[v]){
            if(dis[nv] < INF) continue;
            pq.push({d+cost,nv});
        }
    }
    /*
        dp[mask][p]:=
        すでに通った地点の集合maskに対して現在地点pにいるときの
        最小コスト
    */
    vector<vector<ll>> dp((1<<K),vector<ll>(K,INF));
    for(int k = 0; k < K; k++){
        // 地点SからT[k]に行く
        dp[(1<<k)][k] = dis[T[k]];
    }
    int maskmax = (1<<K);
    for(int mask = 1; mask < maskmax; mask++){
        for(int i = 0; i < K; i++){
            // dp[mask][i]から移動する
            if(dp[mask][i] == INF) continue;
            for(int j = 0; j < K; j++){
                if(i == j) continue;
                if((mask&(1<<j)) > 0) continue;
                if(dist[i][j] == INF) continue;
                int nmask = mask | (1<<j);
                dp[nmask][j] = min(dp[nmask][j],dp[mask][i]+dist[i][T[j]]);
            }
        }
    }
    ll ans = INF;
    for(int i = 0; i < K; i++){
        if(dp[(1<<K)-1][i] == INF or dist[i][S]==INF) continue;
        ans = min(ans,dp[(1<<K)-1][i] + dist[i][S]);
    }
    if(ans < INF) cout << ans << endl;
    else cout << -1 << endl;
}
