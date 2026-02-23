#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,Q; cin >> N >> Q;
    vector<vector<ll>> graph(N);
    vector<ll> V(N);
    for(int i = 0; i < N; i++){
        cin >> V[i];
    }
    for(int i = 1; i < N; i++){
        int par; cin >> par; par--;
        graph[par].push_back(i);    // 親から辿ればよい
    }
    queue<int> que; que.push(0);
    while(!que.empty()){
        int v = que.front(); que.pop();
        ll val = V[v];
        for(int nv : graph[v]){
            V[nv] += val;
            que.push(nv);
        }
    }
    for(int q = 0; q < Q; q++){
        int X; cin >> X; X--;
        cout << V[X] << endl;
    }
}
