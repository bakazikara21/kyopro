#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K;
    cin >> N >> K;
    ll ans = 0;
    vector<ll> minus(N);
    vector<ll> A(N),B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
        ans += A[i];
        minus[i] = (A[i]-B[i]);
    }
    sort(minus.rbegin(),minus.rend());
    for(int i = 0; i < K; i++){
        if(i >= N) break;
        ans -= minus[i];
    }
    cout << ans << endl;
}
