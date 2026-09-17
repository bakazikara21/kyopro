#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N1,N2,M; cin >> N1 >> N2 >> M;
    vector<vector<int>> graph(N1+N2);
    for(int i = 0; i < M; i++){
        int u,v; cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int mx1 = 0, mx2 = 0;
    queue<int> que;
    que.push(0);
    vector<int> dist1(N1,inf),dist2(N1+N2,inf);
    dist1[0] = 0;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int nv : graph[v]){
            if(dist1[nv] < inf) continue;
            dist1[nv] = dist1[v]+1;
            mx1 = max(mx1,dist1[nv]);
            que.push(nv);
        }
    }
    que.push(N1+N2-1);
    dist2[N1+N2-1] = 0;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int nv : graph[v]){
            if(dist2[nv] < inf) continue;
            dist2[nv] = dist2[v]+1;
            mx2 = max(mx2,dist2[nv]);
            que.push(nv);
        }
    }
    cout << mx1 + mx2 + 1 << endl;
}
