#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N;
    cin >> N;
    vector<ll> H(N);
    for(int i = 0; i < N; i++){
        cin >> H[i];
    }
    sort(H.begin(),H.end());
    ll ans = abs(H[0])+abs(H[N-1]);
    for(int i = 0; i < N-1; i++){
        ans += abs(H[i+1]-H[i]);
    }
    cout << ans << endl;
}
