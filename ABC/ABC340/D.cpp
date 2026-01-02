#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
int main(){
    int N;
    cin >> N;

    vector<ll> ans(N,INF);   // stage i minimum Time
    vector<vector<pair<int,ll>>> graph(N); // {to,w}
    vector<ll> A(N-1),B(N-1),X(N-1);
    for(int i = 0; i < N-1; i++){
        cin >> A[i] >> B[i] >> X[i];
        X[i]--;

        graph[i].push_back({i+1,A[i]});
        graph[i].push_back({X[i],B[i]});
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0LL,0});

    while(!pq.empty()){
        auto [dist,v] = pq.top(); pq.pop();
        if(ans[v] < INF) continue;
        ans[v] = dist;  // 確定

        for(auto [to,w] : graph[v]){
            if(ans[to] < INF) continue;

            pq.push({ans[v]+w,to});
        }
    }
    cout << ans[N-1] << endl;
}
