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
        vector<int> from(N,-1);
        color[0] = 0;
        queue<int> que;
        que.push(0);
        from[0] = -1;
        int st,en;
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(int nv : graph[v]){
                if(color[nv] != -1){
                    if(color[nv] == 1-color[v]){
                        continue;
                    }
                    else {
                        // 解が存在する
                        // nv -> ... -> v -> nvという閉路
                        st = v;
                        en = nv;
                        flag = true;
                    }   
                }
                else{
                    color[nv] = 1-color[v];
                    que.push(nv);
                    from[nv] = v;
                }
            }
        }
        if(!flag){
            cout << -1 << endl;
            continue;
        }
        // st -> 0 en -> 0へのパスを出力すればよい
        vector<int> path1, path2;
        int lca = -1;   // 最近傍の共通親
        int now = st;
        while(now != -1){
            path1.push_back(now);
            now = from[now];
        }
        now = en;
        while(now != -1){
            path2.push_back(now);
            now = from[now];
        }
        while(!path1.empty() and !path2.empty() and path1.back() == path2.back()){
            lca = path1.back();
            path1.pop_back();
            path2.pop_back();
        }
        path1.push_back(lca);
        reverse(path2.begin(),path2.end());
        int K = (int)path1.size();
        int L = (int)path2.size();
        cout << K+L << endl;
        for(int k = 0; k < K; k++){
            cout << path1[k]+1 << " ";
        }
        for(int l = 0; l < L; l++){
            cout << path2[l]+1 << " ";
        }
        cout << endl;
    }
}
