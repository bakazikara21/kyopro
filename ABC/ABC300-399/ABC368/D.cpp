#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e9;

int main(){
    int N,K;
    cin >> N >> K;

    vector<vector<int>> graph(N);
    for(int i = 0; i < N-1; i++){
        int u,v;
        cin >> u >> v;
        u--; v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    set<int> st;
    for(int k = 0; k < K; k++){
        int V;
        cin >> V;
        V--;
        st.insert(V);
    }

    vector<int> cnt(N); // 自分以下の部分木の中に含まれる指定頂点の個数

    vector<bool> used(N,false);
    auto dfs = [&](auto self, int v)->int{
        int ans = 0;
        if(st.count(v)) ans++;

        used[v] = true;
        for(int nv : graph[v]){
            if(used[nv]) continue;

            ans += self(self,nv);
        }
        return cnt[v] = ans;
    };
    int v = *st.begin();
    dfs(dfs,v);

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(cnt[i] > 0){
            ans++;
        }
        //cout << "i = " << i << " remain = " << remain[i] << endl;
    }
    cout << ans << endl;
}