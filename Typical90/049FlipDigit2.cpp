#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;

/*
    長さNの任意のビット列Tを"000000000000000..."に一致させるのに
    少なくとも必要なアイテムの合計価格の最大値を求める。
*/
int main(){
    int N,M; cin >> N >> M;
    vector<ll> cost(N);
    vector<pair<int,int>> LR(N);
    for(int i = 0; i < N; i++){
        cin >> cost[i] >> LR[i].first >> LR[i].second;
    }
    /*
        隣接XORの配列 D を考える
        D[i] = S[i-1] xor S[i];
        そうすると S[L]~S[R]がビット反転すると
        D[L]とD[R+1]の値のみビット反転する

        ここで任意のビット列 T を作れる
        <=> 任意の差分列 D を作れる
    */
    vector<int> D(N+1);
    D[0] = 0;
    for(int i = 0; i <= N; i++){

    }
}