#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

/*
    頂点0を根とする根付き木を考える
    ある頂点uの子である頂点v以下の部分木において
    粒子の総和がXvとすると、粒子|Xv|個をu以上のところで
    相殺させる必要がある。葉から順に|Xi|*wiすればよさそう
*/
int main(){
    int N;
    cin >> N;
    vector<int> x(N);
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    // 頂点0を根とする根付き木を考える
    vector<vector<pair<int,ll>>> graph(N);
    for(int i = 0; i < N-1; i++){
        int u,v; ll w;
        cin >> u >> v >> w;
        u--; v--; 
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    // 頂点0からの距離をdfsで計算する
    vector<int> dist(N,inf);
    dist[0] = 0;
    queue<int> que; que.push(0);
    while(!que.empty()){
        int v = que.front(); que.pop();
        int dis = dist[v];
        for(auto [to,w] : graph[v]){
            if(dist[to] < inf) continue;
            dist[to] = dis+1;
            que.push(to);
        }
    }
    priority_queue<pair<int,int>> pq;
    vector<pair<int,int>> dist_ver(N); // {distance, vertex}
    for(int i = 0; i < N; i++){
        dist_ver[i] = {dist[i],i};
        // auto itr = graph[i].begin();
        // while(itr != graph[i].end()){
        //     int to = itr->first;
        //     if(dist[i] < dist[to]){
        //         itr = graph[i].erase(itr);
        //     }
        //     else itr++;
        // }
    }
    sort(dist_ver.rbegin(),dist_ver.rend());
    ll ans = 0;
    for(int i = 0; i < N-1; i++){
        // 葉から順に|Xi|*wiを計算する
        auto [dis,id] = dist_ver[i];
        ll X = x[id];
        for(auto [to,w] : graph[id]){
            if(dist[to] > dis) continue;
            ans += abs(X)*w;
            x[to] += X;
        }
    }
    cout << ans << endl;
}
