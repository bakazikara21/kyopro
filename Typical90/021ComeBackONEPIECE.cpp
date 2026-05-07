#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

// 強連結成分分解の典型問題
/*
    強連結成分(SCC)とは:
    有効グラフにおいて、どの頂点同士も互いに行き来できる極大集合
    SCCに分解して、kC2 をすべてのSCCで足せば終了
*/
int main(){
    int N,M; cin >> N >> M;
    vector<vector<int>> graph(N);
    for(int i = 0; i < M; i++){
        int A,B; cin >> A >> B; A--; B--;
        graph[A].push_back(B);
    }
    // cycleと、そのcycleの頂点数を求めればよい。
    // 1つのcycleにk頂点あるならば ans += kC2;
    ll ans = 0;
    vector<bool> visited(N,false);
    auto dfs = [&](auto self, int v, vector<ll> dist)->ll{
        ll mx = 0;
        int d = dist[v];
        visited[v] = true;
        for(auto nv : graph[v]){
            if(dist[v] >= dist[nv]){
                // cycle発見
                mx = max(mx,dist[v]-dist[nv]+1);
                continue;
            }
            else if(visited[nv]) continue;
            dist[nv] = dist[v]+1;
            mx = max(mx,self(self,nv,dist));
        }
        return mx;
    };
    for(int i = 0; i < N; i++){
        // 頂点iをスタートして辺を辿っていく。O(M+N)
        if(visited[i]) continue;

        vector<ll> dist(N,inf);  // 毎回初期化して、距離が今いる地点より小さかったらサイクルあり
        dist[i] = 0;
        ll k = dfs(dfs,i,dist);
        ans += k*(k-1)/2;
    }
    cout << ans << endl;
}