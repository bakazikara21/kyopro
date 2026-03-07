#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<vector<int>> graph(N);
    for(int i = 0; i < N-1; i++){
        int u,v; cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    map<int,int> mp;
    vector<bool> used(N,false);
    vector<string> ans(N);
    auto dfs = [&](auto self, int v, bool ok)->void{
        if((mp.count(A[v]) and mp[A[v]] >= 1) or ok) {
            ok = true;
            ans[v] = "Yes";
        }
        else ans[v] = "No";
        mp[A[v]]++;
        for(int nv : graph[v]){
            if(used[nv]) continue;
            used[nv] = true;
            self(self,nv,ok);
        }
        mp[A[v]]--;
        return;
    };
    used[0] = true;
    dfs(dfs,0,false);
    for(int i = 0; i < N; i++){
        cout << ans[i] << endl;
    }
}
