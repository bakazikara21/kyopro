#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

ll kurikaesi(ll a, ll b){
    if(b == 1) return (a%mod);
    if(b%2 == 0){
        return kurikaesi(a*a % mod,b/2) % mod;
    }else{
        b--;
        return (a*(kurikaesi(a*a % mod, b/2) % mod)) % mod;
    }
}
int main(){
    ll n,r;
    cin >> n >> r;
    // a/b = a*b^M-2 (mod.M)を使う
    vector<ll> factorial(n+1);
    factorial[0] = 1;
    ll fac = 1;
    for(ll i = 1; i <= n; i++){
        fac *= i;
        fac %= mod;
        factorial[i] = fac;
    }
    ll ans = kurikaesi((factorial[r]*factorial[n-r])%mod,mod-2) % mod;
    ans = (ans * factorial[n]) % mod;
    cout << ans << endl;
}
