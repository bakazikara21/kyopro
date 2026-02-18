#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll MAX = (ll)1e7;
const ll mod = 998244353;

ll kurikaesi(ll a, ll b){
    a %= mod;
    if(b == 0) return 1LL;
    if(b == 1) return a;
    if((b%2) == 0){
        return kurikaesi((a*a)%mod,b/2)%mod;
    }
    else return (a*(kurikaesi((a*a)%mod,b/2)%mod))%mod;
}
class Eratosthenes {
    // エラトステネスの篩と高速素因数分解が可能なクラス
    public:
    ll N;
    vector<bool> isPrime;   // isPrime[i] = (iが素数ならtrue)
    vector<ll> minPrime;    // minPrime[i] = (iを割り切る最小の素数)
    vector<ll> primes;      // N以下の素数のみを持つ配列
    Eratosthenes(ll n): isPrime(n+1,true),minPrime(n+1,n){
        N = n;
        // N以下の素数の全列挙
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
    
    vector<pair<ll,ll>> get_factorization(ll A){
        // Aの素因数分解をO(log(A))で返す関数
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
    
    vector<ll> get_primes(){   
        // N以下の素数を全部格納した配列を返す関数
        return primes;
    }
};
/*
    A1~ANまで高速で素因数分解したときの
    各素数の最大個数(maxi)と二番目の個数(secondi)を保持しておくと
    A1~ANの最小公倍数はp1^max1 * p2^max2 * p3^max3 * ...となるので
    Akを除いた最小公倍数は
    if(Ak.include(pi^maxi)) Max = Max/pi^maxi * pi^secondi
    で求められるがMaxはどうせOverFlowするので
    ans = (Max%mod)*(pi^maxi)^(mod-2) * pi^secondi;
    で求められる。
*/
int main(){
    Eratosthenes erato(MAX);
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int N;
        cin >> N;
        vector<ll> A(N);
        map<ll,ll> no1;  // {素数,指数部分の最大値}
        map<ll,ll> no2;  // {素数,指数部分の2番目に大きい値}
        vector<vector<pair<ll,ll>>> factors(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
            // まず、Max = 全体の最小公倍数%modを求めようよ
            factors[i] = erato.get_factorization(A[i]);
            int jmax = (int)factors[i].size();
            for(int j = 0; j < jmax; j++){
                auto [prime,cnt] = factors[i][j];
                if(no1.count(prime)){
                    if(no1[prime] >= cnt){
                        no2[prime] = max(no2[prime],cnt);
                    }
                    else{
                        no2[prime] = no1[prime];
                        no1[prime] = cnt;
                    }
                }
                else no1[prime] = cnt;
            }
        }
        ll Max = 1;
        for(auto [prime,cnt] : no1){
            Max = Max * kurikaesi(prime,cnt)%mod;
            Max %= mod;
        }
        for(int i = 0; i < N; i++){
            // A[i]以外の最小公倍数
            ll ans = Max;
            int jmax = (int)factors[i].size();
            for(int j = 0; j < jmax; j++){
                auto [prime,cnt] = factors[i][j];
                if(no1[prime] == cnt){
                    ll diff = no1[prime]-no2[prime];
                    ans *= (kurikaesi(kurikaesi(prime,diff)%mod,mod-2)%mod);
                    ans %= mod;
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}
