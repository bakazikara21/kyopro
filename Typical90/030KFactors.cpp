#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

// エラトステネスの篩と高速素因数分解が可能なクラス
class Eratosthenes {
    public:
    ll N;
    vector<bool> isPrime;   // isPrime[i] = (iが素数ならtrue)
    vector<ll> minPrime;    // minPrime[i] = (iを割り切る最小の素数)
    vector<ll> primes;      // N以下の素数のみを持つ配列
    vector<ll> numPrime;    // numPrime[i] = (iが持つ素因数の種類)
    Eratosthenes(ll n): isPrime(n+1,true),minPrime(n+1,n),numPrime(n+1,0){
        N = n;
        // N以下の素数の全列挙 O(nloglog(n))
        isPrime[0] = isPrime[1] = false;
        numPrime[0] = numPrime[1] = 0;
        minPrime[1] = 1;
        for(ll i=2; i<=N; i++) {
            if (isPrime[i]){
                // iが素数ならば、素数の倍数をすべてfalseにする
                minPrime[i] = i;
                primes.push_back(i);
                for (ll j = i+i; j <= N; j+=i){
                    isPrime[j] = false;
                    minPrime[j] = min(minPrime[j],i);
                    numPrime[j]++;  // jは素因数iを持つ
                }
                numPrime[i] = 1;    // iは素数なので1種類の素数からなる
            } 
        }
    }

    // N以下の素数を全部格納した配列を返す関数
    vector<ll> get_primes(){   
        return primes;
    }

    // N以下の各整数の素因数の種類を全部格納した配列を返す関数
    vector<ll> get_numPrime(){   
        return numPrime;
    }
};
int main(){
    int N,K; cin >> N >> K;
    Eratosthenes erato(N);
    vector<ll> ans = erato.get_numPrime();
    int cnt = 0;
    for(int i = 2; i <= N; i++){
        if(ans[i] >= K) cnt++;
        //cout << "ans = " << ans[i] << " ";
    }
    //cout << endl;
    cout << cnt << endl;
}