#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M,T; cin >> N >> M >> T; T--;
    vector<vector<pair<int,ll>>> graph(N);
    for(int i = 0; i < M; i++){
        int u,v; ll C;
        cin >> u >> v >> C; u--; v--;
        graph[u].push_back({v,C});
        graph[v].push_back({u,C});
    }
    vector<ll> fzero(N,-1),ft(N,-1);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto [tim,v] = pq.top(); pq.pop();
        if(fzero[v] != -1) continue;
        fzero[v] = tim;

        for(auto [nv,cost] : graph[v]){
            if(fzero[nv] != -1) continue;
            pq.push({tim+cost,nv});
        }
    }
    pq.push({0,T});
    while(!pq.empty()){
        auto [tim,v] = pq.top(); pq.pop();
        if(ft[v] != -1) continue;
        ft[v] = tim;

        for(auto [nv,cost] : graph[v]){
            if(ft[nv] != -1) continue;
            pq.push({tim+cost,nv});
        }
    }
    ll ans = fzero[T] + ft[0];
    if(fzero[T] == -1 or ft[0] == -1) ans = -1;
    cout << ans << endl;
}
