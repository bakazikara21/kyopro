#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<vector<int>> graph(N);
    for(int i = 0; i < N-1; i++){
        int u,v; cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // 二回bfsして、番号が最も大きい頂点を二つ求める
    int ans1 = 0,ans2 = 0,maxi = 0;
    vector<int> dist(N,inf);
    queue<pair<int,int>> que;
    que.push({0,0});    // 適当な場所から始めてもよい
    while(!que.empty()){
        auto [v,dis] = que.front(); que.pop();
        if(dist[v] < inf) continue;
        dist[v] = dis;
        maxi = max(maxi,dis);
        for(int nv : graph[v]){
            if(dist[nv] < inf) continue;
            que.push({nv,dis+1});
        }
    }
    for(int i = 0; i < N; i++){
        if(dist[i] == maxi){
            ans1 = max(ans1,i);
        }
        dist[i] = inf;
    }
    maxi = 0;
    que.push({ans1,0});    // ans1から始める
    while(!que.empty()){
        auto [v,dis] = que.front(); que.pop();
        if(dist[v] < inf) continue;
        dist[v] = dis;  // ans1からの距離になる
        maxi = max(maxi,dis);
        for(int nv : graph[v]){
            if(dist[nv] < inf) continue;
            que.push({nv,dis+1});
        }
    }
    for(int i = 0; i < N; i++){
        if(dist[i] == maxi){
            ans2 = max(ans2,i);
        }
    }
    vector<int> dist2(N,inf);
    que.push({ans2,0});    // ans2から始める
    while(!que.empty()){
        auto [v,dis] = que.front(); que.pop();
        if(dist2[v] < inf) continue;
        dist2[v] = dis;  // ans2からの距離になる
        for(int nv : graph[v]){
            if(dist2[nv] < inf) continue;
            que.push({nv,dis+1});
        }
    }
    // 木の直径はans1 - ans2とわかった
    ans1++; ans2++;
    //cout << "ans1 = " << ans1 << " ans2 = " << ans2 << endl;
    for(int i = 0; i < N; i++){
        if(dist[i] < dist2[i]) cout << ans2 << endl;
        else if(dist[i] > dist2[i]) cout << ans1 << endl;
        else cout << max(ans1,ans2) << endl;
    }
}
