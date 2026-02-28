#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int Q; cin >> Q;
    for(int q = 0; q < Q; q++){
        int N; cin >> N;
        vector<vector<int>> graph(N);
        for(int i = 0; i < N-1; i++){
            int u,v; cin >> u >> v; u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // 左右の子がいれば+1
        vector<int> dist(N,inf);
        queue<pair<int,int>> que;
        que.push({0,0});    // 0を根付き木とする
        priority_queue<pair<int,int>> pq;
        while(!que.empty()){
            auto [v,dis] = que.front(); que.pop();
            if(dist[v] < inf) continue;
            dist[v] = dis;
            pq.push({dis,v});
            for(int nv : graph[v]){
                if(dist[nv] < inf) continue;
                que.push({nv,dis+1});
            }
        }
        vector<int> cnt(N,0);
        while(!pq.empty()){
            auto [dis,v] = pq.top(); pq.pop();
            int siz = 0;
            int mini1 = inf, mini2 = inf;
            for(int nv : graph[v]){
                //cout << "v = " << v << " nv = " << nv << endl;
                if(dist[nv] < dis){
                    continue;
                }
                // したからもらってる
                siz++;
                cnt[v] += cnt[nv];
                if(mini1 > cnt[nv]){
                    mini2 = mini1;
                    mini1 = cnt[nv];
                }
                else if(mini2 > cnt[nv]){
                    mini2 = cnt[nv];
                }
            }
            if(siz >= 2){
                if(mini1 < inf) cnt[v] -= mini1;
                if(mini2 < inf) cnt[v] -= mini2;
                cnt[v]++;
            }
        }
        cout << cnt[0] << endl;
        for(int i = 0; i < N; i++){
            cout << "i = " << i << " cnt = " << cnt[i] << endl;
        }
        // cout << "distance" << endl;
        // for(int i = 0; i < N; i++){
        //     cout << "i = " << i << " ";
        //     cout << dist[i] << endl;
        // }
        // cout << endl;
    }
}
