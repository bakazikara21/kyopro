#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;

    /*
    */
   int n = 1000000;
   vector<bool> isPrime(n+1, true);
   isPrime[0] = isPrime[1] = false;
   for(ll i=2; i<n; ++i) {
       if (isPrime[i]){
           for (ll j = i*i; j <= n; j+=i) isPrime[j] = false;
       } 
   }
    ll ans = 0;
    for(ll i = 2; i*i*i*i*i*i*i*i <= N; i++){
        // 素数の8乗ならインクリメント
        if(isPrime[i]){
            ans++;
        }
        /*
        */
    }
    // 残るは素数の2乗*素数の2乗の個数
    for(ll i = 2; i*i*i*i <= N; i++){
        for(ll j = i+1; i*i*j*j <= N; j++){
            if(isPrime[i] and isPrime[j]){
                ans++;
            }
            /*
            */
        }
    }
    cout << ans << endl;
}
