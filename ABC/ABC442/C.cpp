#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll comb3(ll n){
    return n*(n-1)*(n-2)/6;
}
int main(){
    int N,M;
    cin >> N >> M;
    
    vector<ll> graph(N);
    for(int i = 0; i < M; i++){
        int u,v;
        cin >> u >> v;
        u--; v--;
        graph[u]++;
        graph[v]++;
    }
    for(int i = 0; i < N; i++){
        ll ans = comb3(N-graph[i]-1);
        cout << ans << " ";
    }
    cout << endl;
}
