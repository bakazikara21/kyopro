#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = (int)1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M; cin >> N >> M;
    vector<vector<pair<int,int>>> graph(N);
    for(int i = 0; i < M; i++){
        int u,v,C; cin >> u >> v >> C; u--; v--;
        graph[u].push_back({v,C});
        graph[v].push_back({u,C});
    }
    vector<int> distONE(N,inf),distN(N,inf);
    // {dist,v}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto [d,v] = pq.top(); pq.pop();
        if(distONE[v] < inf) continue;
        distONE[v] = d;
        for(auto [nv,cost] : graph[v]){
            if(distONE[nv] < inf) continue;
            pq.push({d+cost,nv});
        }
    }
    pq.push({0,N-1});
    while(!pq.empty()){
        auto [d,v] = pq.top(); pq.pop();
        if(distN[v] < inf) continue;
        distN[v] = d;
        for(auto [nv,cost] : graph[v]){
            if(distN[nv] < inf) continue;
            pq.push({d+cost,nv});
        }
    }
    for(int i = 0; i < N; i++){
        if(i == 0){
            cout << distONE[N-1] << endl;
        }
        else if(i == N-1){
            cout << distONE[N-1] << endl;
        }
        else cout << distONE[i]+distN[i] << endl;
    }
}
