#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M,K; cin >> N >> M >> K;
    vector<vector<pair<int,int>>> graph(N);
    for(int i = 0; i < M; i++){
        int u,v,w; cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    vector<int> dist(N,-1);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto [nv,w] : graph[v]){
            if(dist[nv] >= 0 or w < K) continue;
            dist[nv] = dist[v]+1;
            que.push(nv);
        }
    }
    cout << dist[N-1] << endl;
}
