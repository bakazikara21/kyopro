#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;

/*
    M^N通りの整数の各組み合わせにおいて、種類数の総和を求めたい。
    ans = \sum_{k} (kが一度以上選ばれる場合の数) -> 確かにそうかも
    種類数は \sum_{k} (1) -> 整数kが存在すれば1 としてsumをとる
*/
ll powmod(ll a, ll b){
    a %= mod;
    if(b == 0) return 1LL;
    if(b == 1) return a;
    if(b%2 == 0) return powmod((a*a)%mod,b/2)%mod;
    else return (a * (powmod((a*a)%mod,b/2)%mod))%mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N,M; cin >> N >> M;
    vector<vector<int>> A(N,vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> A[i][j];
    }
    vector<ll> dp(N*M+1); // dpとおく。
    /*
        余事象を考えて、kが1度も選ばれない場合の数を求められれば良い。
    */
    vector<vector<ll>> type(N,vector<ll>(N*M+1));   // type[i][V] := A[i]に含まれる整数Vの個数
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            type[i][A[i][j]]++;
        }
    }
    ll ans = 0;
    ll MX = powmod(M,N);
    for(int i = 1; i <= N*M; i++){
        // dp[i]を求める。
        ll mul = 1;
        for(int j = 0; j < N; j++){
            mul *= (M-type[j][i]);
            mul %= mod;
        }
        dp[i] = (mul%mod);
        ans += MX - dp[i];
        ans %= mod;
    }
    
    if(ans < 0) ans += mod;
    cout << ans << endl;
}