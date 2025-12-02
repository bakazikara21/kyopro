#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int keta(ll x){
    int cnt = 0;
    while(x > 0){
        cnt++;
        x /= 10;
    }
    return cnt;
}
int main(){
    int N,M;
    cin >> N >> M;
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    vector<vector<ll>> bigMod(N,vector<ll>(11));
    for(int i = 0; i < N; i++){
        ll ten = 10;
        for(int j = 1; j <= 10; j++){
            // Ai * 10^j 乗のMod Mを求める
            ll a = A[i] % M;
            ten %= M;
            bigMod[i][j] = (a*ten) % M;
            ten *= 10;
        }
    }
    vector<map<ll,ll>> mp(10);
    for(int j = 1; j <= 10; j++){
        for(int i = 0; i < N; i++){
            mp[j-1][bigMod[i][j]]++;
        }
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        int k = keta(A[i]);
        A[i] %= M;
        if(mp[k-1].count((M-A[i])%M)){
            ans += mp[k-1][(M-A[i])%M];
        }
    }
    cout << ans << endl;
}

