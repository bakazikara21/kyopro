#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    ll Y; cin >> Y; // ワープ料金
    vector<vector<pair<ll,ll>>> graph(N);
    for(int i = 0; i < M; i++){
        int u,v; ll T; cin >> u >> v >> T; u--; v--;
        graph[u].push_back({v,T});
        graph[v].push_back({u,T});
    }
    vector<ll> X(N);
    for(int i = 0; i < N; i++) cin >> X[i];

    vector<bool> visited(N,false);
    vector<ll> ans(N,INF);
    ans[0] = 0;
    priority_queue<pair<ll,int>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto [t,v] = pq.top(); pq.pop();
        visited[v] = true;
        ans[v] = t;
        for(auto [nv,T] : graph[v]){
            if(visited[nv]) continue;
            ll mn = min(t+T,t+X[v]+X[nv]+Y);
            pq.push({mn,nv});
        }
    }
    for(int i = 1; i < N; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
