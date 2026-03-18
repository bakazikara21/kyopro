#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<ll> P(N),A(N),B(N);
    for(int i = 0; i < N; i++) cin >> P[i];
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    ll maxi = 0;
    for(int i = 0; i < N; i++){
        maxi = max(maxi,P[i]-A[i]);
    }
    ll ans = accumulate(A.begin(),A.end(),0LL)-accumulate(B.begin(),B.end(),0LL)+maxi;
    cout << ans << endl;
}
