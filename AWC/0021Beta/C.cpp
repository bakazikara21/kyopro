#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K; cin >> N >> K;
    vector<ll> dif(N);
    for(int i = 0; i < N; i++){
        ll C,M; cin >> C >> M;
        dif[i] -= C;
        for(int j = 0; j < M; j++){
            ll P; cin >> P;
            dif[i] += P;
        }
    }
    sort(dif.rbegin(),dif.rend());
    ll ans = 0;
    for(int k = 0; k < K; k++){
        if(dif[k] < 0) break;
        ans += dif[k];
    }
    cout << ans << endl;
}
