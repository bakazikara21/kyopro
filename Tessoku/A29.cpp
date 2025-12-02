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
    ll a,b;
    cin >> a >> b;

    ll ans = kurikaesi(a,b) % mod;
    cout << ans << endl;
}
