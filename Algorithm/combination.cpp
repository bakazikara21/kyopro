#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
const int MAX = 2 * 1000000 + 1;

vector<ll> fuct(MAX);
ll kurikaeshi(ll a, ll b){
    a %= mod;
    if (b == 0) return 1LL;
    if (b == 1) return a;
    if (b % 2 == 0){
        return kurikaeshi(a * a, b / 2) % mod;
    }
    else{
        return (a * (kurikaeshi(a * a, b / 2) % mod)) % mod;
    }
}
ll combination(ll n, ll r){
    if (r == 0 or n == r)
        return 1LL;

    ll fuctorial = kurikaeshi(fuct[n - r], mod - 2) * kurikaeshi(fuct[r], mod - 2);
    fuctorial %= mod;
    return (fuct[n] * fuctorial) % mod;
}
void init(){
    for (ll i = 0; i < MAX; i++){
        if (i == 0){
            fuct[i] = 1;
            continue;
        }
        fuct[i] = i * fuct[i - 1];
        fuct[i] %= mod;
    }
}
