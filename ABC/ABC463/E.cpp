#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

/*
    完全グラフになって辺の本数がオーバーフローするとき、
    頂点を一つ追加して、その頂点と他のすべての頂点を辺で繋げれば、
    辺の本数は +N にしかならずに済む
*/
int main(){
    int N,M; cin >> N >> M;
    ll Y; cin >> Y; // ワープ料金
    ll half = Y/2;
    ll rest = (Y%2 == 1);   // 奇数なら +1 が必要。
    vector<vector<pair<ll,ll>>> graph(N+1); // 頂点を一つ追加
    for(int i = 0; i < M; i++){
        int u,v; ll T; cin >> u >> v >> T; u--; v--;
        graph[u].push_back({v,T});
        graph[v].push_back({u,T});
    }
    vector<ll> X(N);
    for(int i = 0; i < N; i++) cin >> X[i];
    for(int i = 0; i < N; i++){
        graph[N].push_back({i,half+X[i]});
        graph[i].push_back({N,half+X[i]});
    }

    vector<ll> ans(N+1,INF);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto [t,v] = pq.top(); pq.pop();
        if(ans[v] < INF) continue;
        ans[v] = t;
        for(auto [nv,T] : graph[v]){
            if(ans[nv] < INF) continue;
            ll mn = t+T;
            if(nv == N) mn += rest;
            pq.push({mn,nv});
        }
    }
    for(int i = 1; i < N; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
