#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = (int)2e9;
// ダイクストラ法の練習
int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<pair<int,int>>> graph(N);

    for(int i = 0; i < M; i++){
        int A,B,C;
        cin >> A >> B >> C;
        A--; B--;
        graph[A].push_back({C,B});
        graph[B].push_back({C,A});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    vector<int> dist(N,inf);
    vector<bool> used(N,false); // 確定しているかどうか
    dist[0] = 0;
    while(!pq.empty()){
        int dis = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(used[v] == true) continue;
        used[v] = true;
        
        for(auto [ndis,nv] : graph[v]){
            if(used[nv] == true) continue;

            dist[nv] = min(dist[nv], dis+ndis);
            pq.push({dist[nv],nv});
        } 
    }

    for(int k = 0; k < N; k++){
        if(dist[k] == inf) cout << -1 << endl;
        else cout << dist[k] << endl;
    }
}
