#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M;
    cin >> N >> M;
    ll mini = INF;
    for(int i = 0; i < N; i++){
        ll E;
        cin >> E;
        mini = min(mini,E);
    } 
    ll ans = 0;
    for(int i = 0; i < M; i++){
        ll C;
        cin >> C;
        ans += C*mini;
    }
    cout << ans << endl;
}
