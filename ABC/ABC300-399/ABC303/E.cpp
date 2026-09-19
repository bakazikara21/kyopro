#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<vector<int>> graph(N);
    for(int i = 1; i < N; i++){
        int u,v; cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    /*
        次数が1の頂点と、その頂点に隣接している頂点は同一の星である
        次数が1の頂点の隣の頂点が星の核。その核が属する星を取り除いて、
        再び次数が1の頂点を探して、っていうのを繰り返す
        星の中心から星の中心までの距離は3なので、3で割ったあまりを考えれば十分。bfs
    */

    vector<bool> used(N,false);
    vector<int> index(N);
    queue<int> que;
    for(int i = 0; i < N; i++){
        index[i] = graph[i].size();
        if(index[i] == 1){
            used[i] = true;
            que.push(i);
        }
    }
    while(!que.empty()){
        // 頂点v の次数は1
        int v = que.front(); que.pop();
        v = graph[v][0];    // 中心に移動

        for(int nv : graph[v]){
            
        }
    }
    vector<int> ans;
    for(int i = 0; i < N; i++){
        if(used[i]){
            ans.push_back(index[i]);
        }
    }
    sort(ans.begin(),ans.end());
    for(int v : ans) cout << v << " ";
    cout << endl;
}
