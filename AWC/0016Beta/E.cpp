#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

/*
    bitDPは厳しいって
*/
int main(){
    int N,M; cin >> N >> M;
    vector<int> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];
    int S,T; cin >> S >> T; S--; T--;
    vector<vector<int>> graph(N),costs(N,vector<int>(N));
    for(int i = 0; i < M; i++){
        int u,v,w; cin >> u >> v >> w; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        costs[u][v] = w;
        costs[v][u] = w;
    }
    // Pの合計 - 通った辺のコストの合計
    // 同じ辺を通るのは高々2回だけど...
    vector<vector<int>> cnt(N,vector<int>(N));
    auto dfs = [&](auto self, int v, vector<bool> used, ll cost)->ll{
        // 点vスタートで全探索
        if(v == T){
            ll p = 0;
            for(int i = 0; i < N; i++){
                if(used[i]) p += P[i];
            }
            return (p-cost);
        }
        ll ans = -INF;
        for(int nv : graph[v]){
            if(cnt[v][nv] >= 2) continue;
            used[nv] = true;
            cnt[v][nv]++;
            cnt[nv][v]++;
            ans = max(ans,self(self,nv,used,cost+costs[v][nv]));
            cnt[v][nv]--;
            cnt[nv][v]--;
            used[nv] = false;
        }
        return ans;
    };
    vector<bool> used(N,false);
    used[S] = true; 
    cout << dfs(dfs,S,used,0LL) << endl;
}
