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
int main(){
    string S; cin >> S;
    int N = S.size();
    map<char,int> mp;
    vector<int> ids(N,-1);
    for(int i = 0; i < N; i++){
        if(mp.count(S[i])){
            ids[i] = mp[S[i]]; 
        }
        else mp[S[i]] = i;
    }
    vector<int> ch(N,-1);
    int MAX = 1e7;
    Eratosthenes erato(MAX);
    set<int> st;
    vector<int> ans;
    auto dfs = [&](auto self, int id)->void{
        if(id+1 == N){
            int prime = 0;
            int ten = 1;
            for(int i = N-1; i >= 0; i--){
                prime += ch[i]*ten;
                ten *= 10;
            }
            if(erato.isPrime[prime]){
                ans.push_back(prime);
            }
            return;
        }
        if(ids[id+1] != -1){
            ch[id+1] = ch[ids[id+1]];
            self(self,id+1);
            return;
        }
        for(int i = 0; i < 10; i++){
            if(st.count(i)) continue;
            ch[id+1] = i;
            st.insert(i);
            self(self,id+1);
            st.erase(i);
        }
    };
    for(int i = 1; i < 10; i++){
        ch[0] = i;
        st.insert(i);
        dfs(dfs,0);
        st.clear();
    }
    if(ans.size() > 0){
        cout << ans[0] << endl;
    }
    else cout << -1 << endl;
}
