#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,T; cin >> N >> T;
    vector<ll> H(N),C(N);
    for(int i = 0; i < N; i++) cin >> H[i];
    for(int i = 0; i < N; i++) cin >> C[i];
    ll ans = 0;
    for(int i = 0; i < N; i++){
        if(H[i] <= T) ans += C[i];
    }
    cout << ans << endl;
}
