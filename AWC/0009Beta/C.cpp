#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; ll T,K;
    cin >> N >> T >> K;
    vector<ll> H(N);
    ll mini = INF;
    for(int i = 0; i < N; i++){
        cin >> H[i];
        mini = min(H[i],mini);
    }
    ll D = mini-1;
    int ans = 0;
    for(int i = 0; i < N; i++){
        H[i] -= D;
        if(H[i] <= T+K) ans++;
    }
    cout << ans << endl;
}
