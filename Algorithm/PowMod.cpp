#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
    繰り返し二乗法を用いて
    aのb乗をmodで割った余りをO(log|b|)で求める
*/
ll powmod(ll a, ll b, ll mod){
    a %= mod;
    if(b == 0) return (1%mod);
    if(b == 1) return a;
    if((b%2) == 0) return powmod((a*a)%mod,b/2,mod)%mod;
    else return (a*(powmod((a*a)%mod,b/2,mod)%mod))%mod;
}