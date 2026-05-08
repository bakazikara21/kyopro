#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

// Grundy数の練習問題

// 先攻と後攻どちらが必勝なのかを計算する
/*
    ゲームの局面Gに対するGrundy数g(G):= 
    Gから一手で遷移可能な局面の集合を
    {G1,G2,G3,...,Gn}とするとき、
    g(G) = mex{g(G1),g(G2),g(G3),...,g(Gn)}.
    ここで、mexとはその集合に含まれない最小の非負整数を表す。
    また、Gから一手で遷移可能な局面が存在しないとき、
    g(G) = 0　（負け確）
    とする。
    g(G) = 0 -> 後手必勝
    g(G) > 0 -> 先手必勝

    n個のゲームの局面の和 G1+G2+G3+...+Gn のGrundy数は
    g(G1+G2+G3+...+Gn) = g(G1) xor g(G2) xor g(G3) xor ... xor g(Gn)
    で求められることが知られている。
*/
int main(){
    // 左からi番目の山には、白石がW_i個、青石がB_i個ある

    /*
        先攻から交互に以下の操作を繰り返す
        白石が1個以上または青石が2個以上ある山を1つ選ぶ。
        その山にある白石の個数をw, 青石の個数をbとする。
        1. w >= 1のとき選択可能：この山に青石をw個加えて、白石を1個取り除く
        2. b >= 2のとき選択可能：1以上b/2以下の整数kを選んで、青石をk個取り除く。
        1. 2. のどちらの操作も最初に行えなくなったほうの負け

        このルールの下で、先攻と後攻どちらが必勝ですか？
    */
    int N; cin >> N;
    vector<int> W(N),B(N);
    for(int i = 0; i < N; i++) cin >> W[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    // まず各山のGrundy数を求める。g(G)
    // 各山の状態数が2500通りしかないので
    vector<vector<ll>> Grundy(51,vector<ll>(1350));   // すべての状態のGrundy数
    Grundy[0][0] = 0;   // 負け確
    Grundy[0][1] = 0;   // 負け確
    for(int w = 0; w <= 50; w++){
        for(int b = 0; b < 1350; b++){
            // 状態遷移が 高々700通り　しかないのでぎりぎり全探索できる
            vector<bool> mex(700,false);
            if(b >= 2){
                // 2つ目の操作が可能
                for(int k = 1; k <= b/2; k++){
                    mex[Grundy[w][b-k]] = true;
                }
            }
            if(w >= 1){
                // 1つ目の操作が可能
                mex[Grundy[w-1][w+b]] = true;
            }
            Grundy[w][b] = 0;   // Grundy数の候補
            for(int i = 0; i < 700; i++){
                if(mex[i] == false){
                    Grundy[w][b] = i;
                    break;
                }
            }
        }
    }
    ll gr = 0;
    for(int i = 0; i < N; i++){
        gr = gr ^ Grundy[W[i]][B[i]];
    }
    if(gr == 0){
        // 後攻必勝
        cout << "Second" << endl;
    }
    else cout << "First" << endl;
} 