#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

// 天才すぎるよね

/*
    この問題は、各辺が何回使用されるのかと言い換えることが重要である。

    辺eで木を切断したときの片方の頂点集合のサイズをS_eとすると、もう片方は(N-S_e)となる。
    このとき、辺eを通過するパスを持つ頂点の組(i,j)の個数は S_e * (N-S_e)である。
    よって、求める答えは \sum_{e} S_e * (N-S_e)
*/
int main(){
    int N; cin >> N;
    vector<vector<int>> graph(N);
    for(int i = 0; i < N-1; i++){
        int u,v; cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    /*
        この木を頂点0を根とする根付き木と見なす。
        S[0] = N;
        S[葉] = 1;
        となるように葉ノードからdpすればS[]はすべて求める。
    */
    vector<int> dist(N,-1);
    queue<pair<int,int>> que;
    que.push({0,0});
    vector<pair<int,int>> pairs;
    while(!que.empty()){
        auto [v,d] = que.front(); que.pop();
        if(dist[v] >= 0) continue;
        dist[v] = d;
        pairs.push_back({d,v}); // あとで距離が遠いほうから順に
        for(int nv : graph[v]){
            if(dist[nv] >= 0) continue;
            que.push({nv,d+1});
        }
    }
    sort(pairs.rbegin(),pairs.rend());
    vector<ll> S(N,1); 
    for(int i = 0; i < N; i++){
        auto [d,v] = pairs[i];
       
        for(auto nv : graph[v]){
            if(dist[nv] >= dist[v]) continue;
            S[nv] += S[v];
        }
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans += S[i]*(N-S[i]);
    }
    cout << ans << endl;
}