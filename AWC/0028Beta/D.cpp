#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    vector<set<int>> zentei(N);
    vector<vector<int>> graph(N);
    for(int i = 0; i < M; i++){
        int A,B; cin >> A >> B;
        A--; B--;
        zentei[B].insert(A);    // Bの前提にAが含まれる
        graph[A].push_back(B);
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0; i < N; i++){
        if((int)zentei[i].size() == 0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int v = pq.top(); pq.pop();
        cout << v+1 << " ";
        for(int nv : graph[v]){
            zentei[nv].erase(v);
            if((int)zentei[nv].size() == 0) pq.push(nv);
        }
    }
    cout << endl;
}
