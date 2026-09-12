#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M,L;
    ll S,T;
    cin >> N >> M >> L >> S >> T;
    vector<vector<pair<int,ll>>> graph(N);
    for(int i = 0; i < M; i++){
        // M個の辺
        int u,v;
        ll C;
        cin >> u >> v >> C;
        u--; v--;
        graph[u].push_back({v,C});
    }

    set<int> st;
    auto dfs = [&](auto self, int v, int cnt, ll cost)->void{
        if(cnt == L){
            if(S <= cost and cost <= T){
                st.insert(v);
            }
            return;
        }
        for(auto [nv,C] : graph[v]){
            self(self,nv,cnt+1,cost+C);
        }
    };
    dfs(dfs,0,0,0);

    for(int v : st){
        cout << v+1 << " ";
    }
    cout << endl;
}
