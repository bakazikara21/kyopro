#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    vector<int> p(N);
    vector<vector<int>> graph(N);
    for(int i = 1; i < N; i++){
        cin >> p[i]; p[i]--;
        graph[p[i]].push_back(i);
    }
    vector<int> val(N,-1);
    for(int i = 0; i < M; i++){
        int x,y; cin >> x >> y;
        x--;
        val[x] = max(val[x],y);
    }
    int ans = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v = que.front(); que.pop();
        int value = val[v];
        if(value >= 0) ans++;
        for(int nv : graph[v]){
            val[nv] = max(val[nv],value-1);
            que.push(nv);
        }
    }
    cout << ans << endl;
}
