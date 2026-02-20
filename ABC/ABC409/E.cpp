#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N;
    cin >> N;
    vector<int> x(N);
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    vector<set<pair<int,int>>> graph(N);
    for(int i = 0; i < N-1; i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--; 
        graph[u].insert({v,w});
        graph[v].insert({u,w});
    }
    queue<int> que;
    for(int i = 0; i < N; i++){
        // 根から内側に移動させていく
        if(graph[i].size() == 1){
            que.push(i);
        }
    }
    while(!que.empty()){
        int v = que.front(); que.pop();
        int num = x[v];
        
        for(auto [nv,w] : graph[v]){

        }
    }
}
