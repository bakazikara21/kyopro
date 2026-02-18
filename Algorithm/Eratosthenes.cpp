#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// エラトステネスの篩と高速素因数分解が可能なクラス
class Eratosthenes {
    public:
    ll N;
    vector<bool> isPrime;   // isPrime[i] = (iが素数ならtrue)
    vector<ll> minPrime;    // minPrime[i] = (iを割り切る最小の素数)
    vector<ll> primes;      // N以下の素数のみを持つ配列
    Eratosthenes(ll n): isPrime(n+1,true),minPrime(n+1,n){
        N = n;
        // N以下の素数の全列挙 O(nloglog(n))
        isPrime[0] = isPrime[1] = false;
        minPrime[1] = 1;
        for(ll i=2; i<=N; i++) {
            if (isPrime[i]){
                // iが素数ならば、素数の倍数をすべてfalseにする
                minPrime[i] = i;
                primes.push_back(i);
                for (ll j = i*i; j <= N; j+=i){
                    isPrime[j] = false;
                    minPrime[j] = min(minPrime[j],i);
                }
            } 
        }
    }

    // Aの素因数分解をO(log(A))で返す関数
    vector<pair<ll,ll>> get_factorization(ll A){
        // 安全対策：構築したNを超えないかチェック
        assert(A <= N && "A must be less than or equal to N");

        vector<pair<ll,ll>> ans;    // {素数,指数部分}
        while(A > 1){
            ll mini = minPrime[A];  // Aを割り切る最小の素数
            ll cnt = 0;
            while((A%mini) == 0){
                cnt++;
                A /= mini;
            }
            ans.push_back({mini,cnt});
        }
        return ans;
    }

    // N以下の素数を全部格納した配列を返す関数
    vector<ll> get_primes(){   
        return primes;
    }
};