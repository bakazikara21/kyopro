#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<int> T(N);
    for(int i = 0; i < N; i++) cin >> T[i],T[i]--;
    vector<bool> visited(N,false);
    vector<int> lens(N),ans(N);
    auto dfs = [&](auto self, int v, int len = 0)->int{
        lens[v] = len;
        visited[v] = true;
        int nv = T[v];
        if(visited[nv] and ans[nv] == 0){
            return ans[v] = lens[v]-lens[nv]+1;
        }
        else if(visited[nv]) return ans[v] = ans[nv];
        return ans[v] = self(self,nv,len+1);
    };
    for(int i = 0; i < N; i++){
        if(visited[i]){
            cout << ans[i] << " ";
        }
        else cout << dfs(dfs,i) << " ";
    }
}
