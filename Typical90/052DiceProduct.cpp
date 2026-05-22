#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)inf+7;

int main(){
    int N; cin >> N;
    vector<vector<ll>> A(N,vector<ll>(6));
    vector<ll> sum(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 6; j++) cin >> A[i][j], sum[i] += A[i][j];
    }
    ll ans = 1;
    for(int i = 0; i < N; i++){
        ans *= sum[i];
        ans %= mod;
    }
    cout << ans << endl;
}