#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;

/*
    1
    10000 132でWrong Answer
*/
int bit(ll n){
    int ret = 0;
    while(n > 0){
        ret++;
        n /= 10;
    }
    return ret;
}
int main(){
    vector<ll> tens(20);
    tens[0] = 1;
    for(int i = 1; i < 15; i++){
        tens[i] = tens[i-1]*10;
    }
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        // xもMも　N以下　であることに注意
        ll N,M; cin >> N >> M;
        ll ans = 0;
        for(ll x = 1; x <= N; x++){
            for(ll y = 1; y <= N; y++){
                int ybit = bit(y);
                ll concat = x*tens[ybit];
                if((concat%M) == (x%M)) ans++;
            }
        }
        cout << ans%mod << endl;
    }
}
