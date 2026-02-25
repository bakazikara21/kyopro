#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; ll T,C,D;
    cin >> N >> T >> C >> D;
    ll ans = 0;
    ll pls = min(C,D);
    for(int i = 0; i < N; i++){
        ll W; cin >> W;
        if(W >= T) ans += pls;
    }
    cout << ans << endl;
}
