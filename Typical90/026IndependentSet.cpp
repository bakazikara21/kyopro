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
    // 点2彩色して、点の個数が多いほうの集合からN/2頂点取り出せばよい
    int start = -1; // 根となる点を探しに行く
    for(int i = 0; i < N; i++){
        if((int)graph[i].size() == 1){
            start = i;
            break;
        }
    }
    queue<pair<int,int>> que;
    que.push({start,0});
    vector<int> used(N,-1);
    while(!que.empty()){
        auto [v,c] = que.front(); que.pop();
        if(used[v] >= 0) continue;
        used[v] = c;
        for(auto nv : graph[v]){
            if(used[nv] >= 0) continue;
            que.push({nv,1-c});
        }
    }
    // 点2彩色が終わったので、2つの点集合に分ける
    vector<int> zeros;
    vector<int> ones;
    for(int i = 0; i < N; i++){
        if(used[i]){
            ones.push_back(i);
        }
        else zeros.push_back(i);
    }
    int Z = (int)zeros.size();
    int O = (int)ones.size();
    if(Z >= O){
        for(int i = 0; i < N/2; i++){
            cout << zeros[i]+1 << " ";
        }
    }
    else {
        for(int i = 0; i < N/2; i++){
            cout << ones[i]+1 << " ";
        }
    }
    cout << endl;
}