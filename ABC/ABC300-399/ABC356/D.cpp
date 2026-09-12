#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
  
int main(){
    ll N,M;
    cin >> N >> M;    

    ll ans = 0;
    for(int j = 0; j < 60; j++){
        if(((M >> j) & 1LL) == 0) continue;
        // 以下、jビット目が1となるN以下の整数の個数を求める

        ll k = N / (1LL << (j+1));
        ans += ((k%mod)*((1LL << j) % mod))%mod;
        ans %= mod;

        ll start = (1LL << j) + ((k)*((1LL << (j+1))));
        if(N >= start) ans += (N-start + 1)%mod;
        ans %= mod;

        //cout << "k = " << k << " start = " << start << " ans = " << ans << endl;
    }
    cout << ans << endl;
}