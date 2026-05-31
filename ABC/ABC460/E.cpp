#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;

int bit(ll n){
    int ret = 0;
    while(n > 0){
        ret++;
        n /= 10;
    }
    return ret;
}
int main(){
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        // xもMも　N以下　であることに注意
        ll N,M; cin >> N >> M;
        ll K = N/M;
        ll L = 0;
        vector<ll> ok(20);
        vector<ll> tensM(20);
        vector<ll> tensMOD(20);
        tensM[0] = 1;
        tensMOD[0] = 1;
        for(int i = 1; i < 20; i++){
            tensM[i] = tensM[i-1]*10;
            tensM[i] %= M;
            tensMOD[i] = tensMOD[i-1]*10;
            tensMOD[i] %= mod;
        }
        ll ans = 0;
        int ybit = bit(N);
        for(int i = 1; i < ybit; i++){
            ll tm = (tensM[i]-1)%M;
            if(tm < 0) tm += M;
            ll d = __gcd(M,tm);
            // x = M/d の倍数ならなんでもOK!
            // yの個数は9*tens[i-1]個
            ll X = N / (M/d);   X %= mod;
            ll Y = 9*tensMOD[i-1];  Y %= mod;
            ans += X*Y;
            ans %= mod;
        }
        ll tm = (tensM[ybit]-1)%M;
        if(tm < 0) tm += M;
        ll d = __gcd(M,tm);
        // x = M/d の倍数ならなんでもOK!
        // yの個数はN-tens[i-1]+1個
        ll X = N / (M/d);   X %= mod;
        ll Y = (N-tensMOD[ybit-1]+1);  Y %= mod;
        ans += X*Y;
        ans %= mod;
        cout << ans << endl;
    }
}
