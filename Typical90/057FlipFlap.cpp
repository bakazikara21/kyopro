#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;

int main(){
    int N,M; cin >> N >> M;
    for(int i = 0; i < N; i++){
        // N個のスイッチとM枚のパネルがある。
        // 各switchは一度しか押せない
        // スイッチを押すと、T枚のパネルの裏表がひっくり返る
    }
    string S = "";
    for(int i = 0; i < M; i++){
        char s; cin >> s;
        S += s;
    }
    // 現在、パネルの状態が 0000000...だけど
    // これを S に一致させたい。一致させる場合の数を求めよ。
    // 各スイッチで反転するパネルを行列とみなして行基本変形で標準形にする
    // 上から必要なら選び、求めるSに一致するならば、2^(0がならぶ行の数)
}