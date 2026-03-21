#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ll N,D,K; cin >> N >> D >> K;
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ll W; cin >> W;
        if(W-D*K >= 1) ans++;
    }
    cout << ans << endl;
}
