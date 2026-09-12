#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 2147483647;

ll kurikaesi(ll a, ll b){
    if(b == 0) return 1LL;
    if(b == 1) return (a%mod);
    if((b%2) == 0){
        return kurikaesi((a*a)%mod,b/2)%mod;
    }
    else return ((a%mod) * (kurikaesi((a*a)%mod,b/2)%mod))%mod;
}
int main(){
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        string A,B; cin >> A >> B;
        int N = (int)A.size();

        ll hashA = 0, hashB = 0;    // A,Bを整数になおしてmodをとる
        vector<ll> ruijo(N,0);
        for(int i = 0; i < N; i++){
            if(A[i] == '0') ruijo[i] = kurikaesi(10,(ll)i)%mod;
            else ruijo[i] = (kurikaesi(10,(ll)i) * 2)%mod;
            hashA += ruijo[i];
            hashA %= mod;

            if(B[i] == '0') hashB += kurikaesi(10,(ll)i)%mod;
            else hashB += (kurikaesi(10,(ll)i) * 2)%mod;
            hashB %= mod;
        }
        bool ok = false;
        int ans = 0;
        if(hashA == hashB){
            cout << ans << endl;
            continue;
        }
        //cout << "hashA = " << hashA << " hashB = " << hashB << endl;
        for(int i = 0; i < N-1; i++){
            // A[i]を一番後ろの文字にしたときのハッシュ値の更新
            if(A[i] == '0'){
                hashA -= 1;  // A[i]単体のハッシュ値を引く
                if(hashA < 0) hashA += mod;
                hashA = (hashA * kurikaesi(10,mod-2))%mod;  // hashAを10で割る
                hashA += kurikaesi(10,(ll)(N-1))%mod;
            } 
            else{
                hashA -= 2;  // A[i]単体のハッシュ値を引く
                if(hashA < 0) hashA += mod;
                hashA = (hashA * kurikaesi(10,mod-2))%mod;  // hashAを10で割る
                hashA += (kurikaesi(10,(ll)(N-1)) * 2)%mod;
            } 
            hashA %= mod;
            if(hashA == hashB){
                ans = i+1;
                ok = true;
                break;
            }
            //cout << "num = " << i+1 << " hashA = " << hashA << endl;
        }
        if(ok){
            cout << ans << endl;
        }
        else cout << -1 << endl;
    }
}
