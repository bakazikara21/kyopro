#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)10007; 
ll kurikaesi(ll a, ll b){
    if(b == 0) return 1LL;
    if(b == 1) return a%mod;
    if((b%2) == 0) return kurikaesi((a*a)%mod,b/2)%mod;
    else return ((a%mod)*(kurikaesi((a*a)%mod,b/2))%mod)%mod;
}
ll kurikaesi2(ll a, ll b, ll M){
    if(b == 0) return 1LL;
    if(b == 1) return a%M;
    if((b%2) == 0) return kurikaesi2((a*a)%M,b/2,M)%M;
    else return ((a%M)*(kurikaesi2((a*a)%M,b/2,M))%M)%M;
}
ll sigma(ll c, ll l){
    return (((c*kurikaesi(9,mod-2))%mod)*(kurikaesi(10,l)-1))%mod;
}
ll sigm(ll c, ll l, ll M){
    return (((c*kurikaesi2(9,M-2,M))%M)*(kurikaesi2(10,l,M)-1))%M;
}
int main(){
    int K,M; cin >> K >> M;
    vector<pair<int,int>> query(K);
    for(int k = 0; k < K; k++){
        cin >> query[k].first >> query[k].second;
    }
    ll ans = kurikaesi(M,mod-2);
    // N%mod N%Mがあれば解ける
    ll md = 0,Md = 0;
    ll nowm = 1, nowM = 1;
    for(int k = K-1; k >= 0; k--){
        auto [c,l] = query[k];
        md += sigma(c,l)*nowm; md %= mod;
        Md += sigm(c,l,M)*nowM; Md %= M;
        nowm = (nowm* kurikaesi(10,l))%mod;
        nowM = (nowM* kurikaesi2(10,l,M))%M;

    }
    ll dif = (md-Md)%mod;
    if(dif < 0) dif += mod;
    ans = (ans * dif)%mod;
    cout << ans << endl;
}
