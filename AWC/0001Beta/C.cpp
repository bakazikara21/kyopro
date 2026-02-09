#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K;
    cin >> N >> K;
    vector<ll> D(N);
    for(int i = 0; i < N; i++){
        cin >> D[i];
    }
    ll ans = 0;
    sort(D.begin(),D.end());
    for(int i = 0; i < N-K; i++){
        ans += D[i];
    }
    cout << ans << endl;
}
