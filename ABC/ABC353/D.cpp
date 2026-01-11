#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

ll kurikaesi(ll a, ll b){
    if(b == 1) return a%mod;

    if(b % 2 == 0){
        return (kurikaesi(a*a % mod,b/2))%mod;
    }
    else return ((a%mod)*(kurikaesi(a*a % mod,b/2))%mod)%mod;
}
int main(){
    int N;
    cin >> N;
    vector<ll> A(N),presum(N+1),bit(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        presum[i+1] = presum[i]%mod +A[i]%mod;
        presum[i+1] %= mod;

        ll ten = 1;
        int cnt = 0;
        while(ten <= A[i]){
            cnt++;
            ten *= 10;
        }
        bit[i] = cnt;
    }
    // (A[0]+A[1]+...+A[j-1])*10^(|A[j]|) + A[j]
    ll sum = 0;
    for(int j = 1; j < N; j++){
        sum += ((presum[j]*(kurikaesi(10,bit[j]) % mod)) % mod) + (A[j]*j) % mod;
        sum %= mod;
    }
    cout << sum << endl;
}
