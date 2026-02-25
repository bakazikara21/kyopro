#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    set<pair<int,int>> st;
    ll ans = 0;
    for(int i = 0; i < M; i++){
        int u,v; cin >> u >> v;
        st.insert({u,v});
        if(st.count({v,u})) ans++;
    }
    cout << ans << endl;
}
