#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

/*
    頂点倍加というテクニックらしい
    u -> vの辺に重みwがついているとき
    dp[v][val ^ w] = (dp[u][val]==true);
*/
int main(){
    const int MAX = 1024;
    int N,M;
    cin >> N >> M;
    vector<vector<pair<int,int>>> edges(N);
   
    for(int i = 0; i < M; i++){
        int u,v,W;
        cin >> u >> v >> W;
        u--; v--;
        edges[u].push_back({v,W});
    }
    vector<vector<bool>> graph(N,vector<bool>(MAX,false));
    //graph[0][0] = true;    // 始点
    queue<pair<int,int>> que;
    que.push({0,0});
    while(!que.empty()){
        auto [v,num] = que.front(); que.pop();
        if(graph[v][num] == true) continue;
        graph[v][num] = true;

        for(auto [to,w] : edges[v]){
            if(graph[to][num^w] == true) continue;

            que.push({to,num^w});
        }
    }
    int ans = inf;
    for(int i = 0; i < MAX; i++){
        if(graph[N-1][i] == false) continue;
        ans = min(ans,i);
    }
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
}
