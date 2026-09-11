#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    for(ll &a : A) cin >> a;
    sort(A.begin(),A.end());
    ll sum = accumulate(A.begin(),A.end(),0LL);
    ll avg = sum/N;
    ll r = sum % N;

    ll ans = 0;
    ll mx = avg+1;
    for(int i = 0; i < N-r; i++){
        ll a = A[i];
        ans += abs(a-avg);
    }
    for(int i = N-r; i < N; i++){
        ll a = A[i];
        ans += abs(a-mx);
    }
    cout << ans/2 << endl;
}
/*
    9 1 2
    -> 8 2 2 
    -> 7 3 2
    -> 6 4 2
    -> 5 4 3
    -> 4 4 4

    9 1 4
    -> 8 2 4
    -> 7 3 4
    -> 6 4 4
    -> 5 4 4

    9 1 1
    -> 8 2 1
    -> 7 3 1
    -> 6 3 2
    -> 5 3 3
    -> 4 4 3
*/
