#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;
/*
    リスの順番は関係ないことを利用する。
    根に近いリスからCombinationを使ってアメを選んでいけばよい。
*/
ll powMod(ll a, ll b){
    a %= mod;
    if(b == 0) return 1LL;
    if(b == 1) return a;

    if((b%2) == 0) return powMod((a*a)%mod,b/2)%mod;
    else return (a * (powMod((a*a)%mod,b/2)%mod))%mod;
}
ll nCr(ll n, ll r){
    // n * (n-1) * (n-2) * ... * (n-r+1) / r!
    ll ret = 1;
    for(ll i = n; i >= n-r+1; i--){
        ret *= i%mod;
        ret %= mod;
    }
    ll farcotrial = 1;
    for(ll i = 1; i <= r; i++){
        farcotrial *= i;
        farcotrial %= mod;
    }
    ll b = powMod(farcotrial,mod-2);
    return (ret*b)%mod;
}
int main(){
    int N; cin >> N;
    vector<ll> P(N),C(N),D(N);
    vector<vector<int>> graph(N);   // 頂点i から葉へ向かう辺
    for(int i = 1; i < N; i++) cin >> P[i], P[i]--; // 頂点i の親の番号
    for(int i = 1; i < N; i++){
        graph[P[i]].push_back(i);
    }
    for(int i = 0; i < N; i++) cin >> C[i]; // 頂点i のアメの個数
    for(int i = 0; i < N; i++) cin >> D[i]; // 頂点i を根とした部分木からD[i]個のアメをとってくる。

    bool ok = true;
    ll ans = 1;
    vector<int> depth(N,inf);   // 頂点i の深さ
    depth[0] = 0;
    queue<int> que;
    que.push(0);

    priority_queue<pair<int,int>> pq;
    while(!que.empty()){
        int v = que.front(); que.pop();
        int d = depth[v];
        pq.push({d,v});
        for(auto nv : graph[v]){
            depth[nv] = d+1;
            que.push(nv);
        }
    }
  
    while(!pq.empty()){
        // 深い順に
        auto [dep, v] = pq.top(); pq.pop();
        auto ame = D[v];    // 頂点v以下から採取するアメの個数
        ll num = C[v];  // 頂点v以下のアメの個数
        int nv = P[v];  // 頂点vの親の頂点

        if(num < ame){
            ok = false;
            break;
        }
        ans *= nCr(num,ame);    // num個からame個選ぶ。
        ans %= mod;
        //cout << "v = " << v << " nv = " << nv << " ans = " << ans << " num = " << num << " ame = " << ame << endl;
        num -= ame; // ame個のアメを回収する。
        
        if(v == 0) break;
        C[nv] += num;   // 親に伝播させる
    }
    if(!ok) cout << 0 << endl;
    else cout << ans << endl;
}
