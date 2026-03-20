#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M,K; cin >> N >> M >> K;
    vector<vector<pair<int,ll>>> graph(N);
    for(int i = 0; i < M; i++){
        int u,v; ll T; cin >> u >> v >> T;
        u--; v--;
        graph[u].push_back({v,T});
        graph[v].push_back({u,T});
    }
    vector<int> P(K);
    for(int i = 0; i < K; i++) cin >> P[i],P[i]--;
    vector<vector<ll>> dist(K,vector<ll>(N,INF));
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    vector<ll> dis(N,INF);  // 頂点0からの距離
    pq.push({0,0});
    while(!pq.empty()){
        auto [d,v] = pq.top(); pq.pop();
        if(dis[v] < INF) continue;
        dis[v] = d;
        for(auto [nv,cost] : graph[v]){
            if(dis[nv] < INF) continue;
            pq.push({d+cost,nv});
        }
    }
    for(int k = 0; k < K; k++){
        pq.push({0,P[k]});
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
    bool ok = true;
    ll ans = 0;
    for(int k = 0; k < K; k++){
        if(k == 0){ 
            if(dis[P[k]] == INF) ok = false;
            else ans += dis[P[k]]; 
        }
        else {
            if(P[k] == P[k-1]) continue;
            // P[k-1]からP[k]
            if(dist[k-1][P[k]] == INF) ok = false;
            else ans += dist[k-1][P[k]];
        }
    }
    if(dist[K-1][N-1] == INF) ok = false;
    else ans += dist[K-1][N-1];
    if(ok) cout << ans << endl;
    else cout << -1 << endl;
}
