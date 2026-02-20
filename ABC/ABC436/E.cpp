#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    (1,2,3,...,N)の順列P = (P1, P2, P3, P4, P5, ... , PN)を
    (1,2,3,...,N)と一致させるために必要なswapの回数Kは
    N個の頂点からなるグラフを考えて、i = 1,2,3,...Nに対して
    iとPiを結ぶ辺を追加する。このグラフの連結成分の個数をCとすると
    K = N - Cである。
*/
int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    int correct = 0;
    for(int i = 0; i < N; i++){
        cin >> P[i];
        P[i]--;
        if(P[i] == i) correct++;
    }
    // すでに合っている個数= correct
    ll ans = N-correct;
    for(int i = 0; i < N; i++){
        if(P[i] == i) continue;
        //P[i]番目の値とP[P[i]]
        if(P[P[P[i]]] > i) ans++;
    }
    cout << ans << endl;
}