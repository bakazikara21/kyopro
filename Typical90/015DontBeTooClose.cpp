#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = (int)1e9;
const ll mod = 1000000007;
const int NMAX = 100000;
/*
    1,2,3,...,Nの中から
    差がk以上となるようにr個の整数を選ぶ場合の数は
    nCr(N-(k-1)*(r-1), r)で求められる
*/
ll powmod(ll a, ll b){
    a %= mod;
    if(b == 0) return 1LL;
    if(b == 1) return a;
    if((b%2) == 0) return powmod((a*a)%mod,b/2)%mod;
    else return (a*(powmod((a*a)%mod,b/2)%mod))%mod;
}
vector<ll> factorial(NMAX+1,1);
ll nCr(ll n, ll r){
    ll rfact = powmod(factorial[r],mod-2);
    ll nrfact = powmod(factorial[n-r],mod-2);
    ll fact = (rfact*nrfact)%mod;
    return (factorial[n]*fact)%mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N; cin >> N;

    for(int i = 2; i <= N; i++){
        factorial[i] = (factorial[i-1]*i)%mod;
    }
    // 出力パート
    for(int k = 1; k <= N; k++){
        ll ans = 0;
        ll r = 1;   // ボールをr個選ぶとき
        while(N-(k-1)*(r-1) >= r){
            ans += nCr(N-(k-1)*(r-1),r);
            ans %= mod;
            r++;
        }
        cout << ans%mod << endl;
    }
}
