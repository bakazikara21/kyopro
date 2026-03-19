#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)10007; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<vector<int>> graph(N);
    for(int i = 0; i < N-1; i++){
        int u,v; cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int start = 0;
    vector<int> dist(N,-1);
    vector<bool> used(N,false);
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    int maxi = 0;
    while(!que.empty()){
        int v = que.front(); que.pop();
        if(used[v]) continue;
        used[v] = true;
        for(int nv : graph[v]){
            if(used[nv]) continue;
            dist[nv] = dist[v]+1;
            maxi = max(maxi,dist[nv]);
            que.push(nv);
        }
    }
    for(int i = 0; i < N; i++){
        used[i] = false;
        if(dist[i] == maxi){
            start = i;
        }
        dist[i] = -1;
    }
    que.push(start);
    dist[start] = 0;
    maxi = 0;
    while(!que.empty()){
        int v = que.front(); que.pop();
        if(used[v]) continue;
        used[v] = true;
        for(int nv : graph[v]){
            if(used[nv]) continue;
            dist[nv] = dist[v]+1;
            maxi = max(maxi,dist[nv]);
            que.push(nv);
        }
    }
    cout << maxi+1 << endl;
}
