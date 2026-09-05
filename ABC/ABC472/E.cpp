#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        bool flag = false;
        // 奇数個の頂点からなる閉路があるならば、二部グラフは作れない
        int N,M; cin >> N >> M;
        vector<vector<int>> graph(N);
        for(int i = 0; i < M; i++){
            int u,v; cin >> u >> v; u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> color(N,-1);
        color[0] = 0;
        queue<int> que;
        que.push(0);
        int st,en;
        while(!que.empty() and !flag){
            int v = que.front(); que.pop();
            for(int nv : graph[v]){
                if(color[nv] != -1){
                    if(color[nv] == 1-color[v]){
                        continue;
                    }
                    else {
                        // 解が存在する
                        // nv -> ... -> v -> nvという閉路
                        st = nv;
                        en = v;
                        flag = true;
                        graph[v].erase(
                            // removeは対象の値を後ろに追いやって、追いやった最初のiteratorを返す
                            remove(graph[v].begin(), graph[v].end(), nv),
                            graph[v].end()
                        );

                        graph[nv].erase(
                            remove(graph[nv].begin(), graph[nv].end(), v),
                            graph[nv].end()
                        );
                        break;
                    }   
                }
                else{
                    color[nv] = 1-color[v];
                    que.push(nv);
                }
            }
        }
        if(!flag){
            cout << -1 << endl;
            continue;
        }
        // st -> enへのパスを出力すればよい
        vector<bool> used(N,false);
        vector<int> path;
        auto dfs = [&](auto self, int v, int goal)->bool{
            used[v] = true;
            if(v == goal){
                path.push_back(v);
                return true;
            }
            for(int nv : graph[v]){
                if(used[nv]) continue;
                if(self(self,nv,goal)){
                    path.push_back(v);
                    return true;
                }
            }
            return false;
        };
        dfs(dfs,st,en);
        int K = (int)path.size();
        cout << K << endl;
        for(int k = 0; k < K; k++){
            cout << path[k]+1 << " ";
        }
        cout << endl;
    }
}
