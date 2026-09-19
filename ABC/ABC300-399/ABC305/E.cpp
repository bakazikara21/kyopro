#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M,K; cin >> N >> M >> K;
    vector<vector<int>> graph(N);
    for(int i = 0; i < M; i++){
        int u,v; cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> p(K),h(N,-1);
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < K; i++){
        int H;
        cin >> p[i] >> H;
        p[i]--;
        h[p[i]] = H;
        pq.push({H,p[i]});
    }

    while(!pq.empty()){
        auto [H,v] = pq.top(); pq.pop();
        if(H == 0) continue;
        for(int nv : graph[v]){
            if(H-1 <= h[nv]) continue;
            h[nv] = H-1;
            pq.push({H-1,nv});
        }
    }
    
    vector<int> ans;
    for(int i = 0; i < N; i++){
        if(h[i] >= 0){
            ans.push_back(i+1);
        }
    }
    cout << ans.size() << endl;
    for(int v : ans) cout << v << " ";
    cout << endl;
}
