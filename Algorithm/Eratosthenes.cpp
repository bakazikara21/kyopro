#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// エラトステネスの篩によるN以下の素数の全列挙
// O(nlog(n))
int main(){
    const ll N = (ll)1e6;
    vector<bool> isPrime(N+1, true);
    isPrime[0] = isPrime[1] = false;
    for(ll i=2; i<N; ++i) {
        if (isPrime[i]){
            for (ll j = i*i; j <= N; j+=i) isPrime[j] = false;
        } 
    }
}