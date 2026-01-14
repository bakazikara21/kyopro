#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
XOR を扱う問題では、各bit毎に分けて考えることが有効である場合が多いです。
bit演算は桁ごとに独立して計算できる
*/
int main(){
    // すべての整数A[i]は27ビットで表現できることに注目
    int N;
    cin >> N;
    vector<ll> A(N),sum(N+1);
    for(ll &a : A) cin >> a;

    // A[i]^A[i+1]^...^A[j] = xorsum[j+1]^xorsum[i]
    vector<ll> xorsum(N+1);
    for(int i = 0; i < N; i++){
        xorsum[i+1] = xorsum[i]^A[i];
        sum[i+1] = sum[i]+A[i];
    }
    /*
    xorsum[i]とxorsum[j]のkビット目が1なら +2^k
    これをi<j,0 <= k <= 26でシグマをとればよい
    -> xorsum[i]とxorsum[j]のkビット目が異なるならば +2^k
    -> xorsumのkビット目が0の個数 * xorsumのkビット目が1の個数 * 2^k
    これを0 <= k <= 26でシグマをとればよい
    */
    // B[k] := xorsum[i]のkビット目が1なら+1
    vector<ll> B(27);  // kビット目が1の個数 <= N-1
    for(int i = 0; i <= N; i++){
        for(int k = 0; k < 27; k++){
            if((xorsum[i] >> k) & 1){
                B[k] += 1;
            }
        }
    }
    ll ans = 0;
    for(int k = 0; k < 27; k++){
        ans += B[k]*(N+1-B[k])*(1LL << k);
    }
    ans -= sum[N];
    cout << ans << endl;
}
