#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K;
    cin >> N >> K;
    vector<ll> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];
    sort(H.begin(),H.end());
    ll ans = 0;
    for(int i = 0; i < N-K; i++){
        ans += H[i];
    }
    ans += K;
    cout << ans << endl;
}
