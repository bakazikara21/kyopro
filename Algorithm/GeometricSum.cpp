#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
    PowModと偶奇で場合分けする漸化式を用いて
    1 + x^1 + x^2 + x^3 + ... + x^{n-1}
    をmodで割った余りをO(log|n|)で求める
*/
ll powmod(ll a, ll b, ll mod){
    a %= mod;
    if(b == 0) return (1%mod);
    if(b == 1) return a;
    if((b%2) == 0) return powmod((a*a)%mod,b/2,mod)%mod;
    else return (a*(powmod((a*a)%mod,b/2,mod)%mod))%mod;
}

// 等比数列の和をmodで割った余りを返す関数
ll geometricSum(ll x, ll n, ll mod){
    if(n == 1) return (1%mod);

    if((n%2) == 0) return ((powmod(x,n/2,mod)+1)*geometricSum(x,n/2,mod))%mod;
    else return ((1+x*geometricSum(x,n-1,mod)))%mod;
}