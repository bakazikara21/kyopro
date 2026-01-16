#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

int prime_factor(int N){
    // 整数Nの素因数の個数を返す。
    int num = 0;
  
    for(int i = 2; i*i <= N; i++){
        while(N%i == 0){
            num++;
            N /= i;
        }
    }

    if(N > 1){
        // 素数が1つ残っている場合
        num++;
    }

    return num;
}
int main(){
    /*
        素因数の個数を石の個数とすれば
        ただのGrundy数による必勝パターンの問題
    */
    // 現在のGrundy数が0ならBrunoの勝利
    int N;
    cin >> N;
    vector<int> A(N);
    for(int &a : A) cin >> a;

    // 素因数の個数は高々17個
    vector<int> Grundy(18);
    Grundy[0] = 0;  // 素因数の個数が0個のとき、負け確
    Grundy[1] = 1;  // 素因数の個数が1個のとき、0を除く最小の非負整数1となる
    for(int i = 0; i < 18; i++){
        Grundy[i] = i;
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        A[i] = prime_factor(A[i]);
        ans ^= Grundy[A[i]];
    }
    if(ans == 0){
        cout << "Bruno" << endl;
    }
    else{
        cout << "Anna" << endl;
    }
}