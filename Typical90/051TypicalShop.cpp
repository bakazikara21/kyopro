#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    // 半分全列挙
    int N,K; ll P; cin >> N >> K >> P;
    int M = N/2;
    vector<ll> A(M),B(N-M);
    for(int i = 0; i < M; i++) cin >> A[i];
    for(int i = 0; i < N-M; i++) cin >> B[i];

    vector<vector<ll>> comA(M+1),comB(N-M+1); // comb[i] := i個選んだときの値段の集合
    int mmx = 1 << M;
    for(int m = 1; m < mmx; m++){
        int bitCnt = 0;
        ll cost = 0;
        for(int bit = 0; bit < M; bit++){
            if((m >> bit)&1){
                bitCnt++;
                cost += A[bit];
            }
        }
        if(cost <= P) comA[bitCnt].push_back(cost);
    }
    mmx = 1 << (N-M);
    for(int m = 1; m < mmx; m++){
        int bitCnt = 0;
        ll cost = 0;
        for(int bit = 0; bit < N-M; bit++){
            if((m >> bit)&1){
                bitCnt++;
                cost += B[bit];
            }
        }
        if(cost <= P) comB[bitCnt].push_back(cost);
    }
    for(int i = 1; i <= N-M; i++){
        sort(comB[i].begin(),comB[i].end());
    }
    // 以下がボトルネック 40 * 10^6
    comA[0].push_back(0);
    comB[0].push_back(0);
    ll ans = 0;
    for(int a = 0; a <= M; a++){
        int b = K-a;
        if(b < 0 or b > N-M) continue;
        for(ll cost : comA[a]){
            ll target = P - cost;
            
            // target以下の個数を求める。
            ll cnt = upper_bound(comB[b].begin(),comB[b].end(),target)-comB[b].begin();
            ans += cnt;
        }
    }
    cout << ans << endl;
}