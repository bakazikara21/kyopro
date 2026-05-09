#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

// a * b <= 100 <=> a <= 100/b (切り捨て)
ll gcd(ll a, ll b){
    if(a < b) swap(a,b);
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
int main(){
    ll A,B; cin >> A >> B;
    ll k = gcd(A,B);
    ll r = A/k;
    ll ans = r * B; // r * B <= 10^18の必要十分条件は?

    // 1e18がBで割り切れるときは、これでよい。割り切れないときもこれでよいらしい。
    if(r > (ll)1e18/B){    // r * B > 10^18ならout
        cout << "Large" << endl;
    }
    else cout << ans << endl;
}