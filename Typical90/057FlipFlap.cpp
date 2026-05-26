#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;

void GaussianElimination(vector<vector<int>> &matrix){
    // 掃き出し法によって matrix を階段行列にする
    // matrixはN * Mの行列
    int N = (int)matrix.size();
    int M = (int)matrix[0].size();
    
    int row = 0; int col = 0;
    while(row < N and col < M){
        while(matrix[row][col] == 0){
            // 対象の成分が0ならば
            for(int i = row+1; i < N; i++){
                if(matrix[i][col] != 0){
                    // 非ゼロ成分を見つけたらrow行目とi行目を交換
                    swap(matrix[row],matrix[i]);
                    break;
                }
            }
            if(matrix[row][col] == 0){
                // 対象の成分が非ゼロの行がないとき
                col++;  // 1つ進める
                if(col == M) break;
            }
        }
        if(col == M) break;
        // matrix[row][col] == 1のとき
        for(int r = 0; r < N; r++){
            if(r == row) continue;

            if(matrix[r][col] != 0){
                // col列目はすべて0にする！
                for(int j = 0; j < M; j++){
                    matrix[r][j] ^= matrix[row][j];
                }
            }
        }
        row++; col++;
    }
    // cout << "掃き出し法のあと" << endl;
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}
int main(){
    int N,M; cin >> N >> M;
    vector<vector<int>> matrix(N,vector<int>(M));   // N行 M列　の行列
    for(int i = 0; i < N; i++){
        // N個のスイッチとM枚のパネルがある。
        // 各switchは一度しか押せない
        // スイッチを押すと、T枚のパネルの裏表がひっくり返る
        int T; cin >> T;
        for(int t = 0; t < T; t++){
            int A; cin >> A; A--;
            matrix[i][A] = 1;
        }
    }
    vector<int> S(M);
    for(int i = 0; i < M; i++){
        cin >> S[i];
    }
    // 現在、パネルの状態が 0000000...だけど
    // これを S に一致させたい。一致させる場合の数を求めよ。
    // 各スイッチで反転するパネルを行列とみなして行基本変形で標準形にする
    // 上から必要なら選び、求めるSに一致するならば、2^(0がならぶ行の数)
    // 行基本変形しても、場合の数は変わらないことと、計算が変わるだけということに注意

    // 行列matrixに対して行基本変形を施す。(2進数の加減算のみ)
    GaussianElimination(matrix);
    vector<int> idr(M,-1); // idr[col]:col列目に1がたつ行を持つ
    int zero = 0;    // ゼロ行ベクトルがいくつあるのか(N-rank(A))
    for(int i = 0; i < N; i++){
        bool ok = true;
        for(int j = 0; j < M; j++){
            if(matrix[i][j] != 0){
                if(idr[j] == -1) idr[j] = i;
                ok = false;
                break;
            }
        }
        if(ok) zero++;
    }
    bool ok = true;
    for(int i = 0; i < M; i++){
        if(S[i] == 1){
            if(idr[i] == -1){
                ok = false;
                break;
            }
            // matrixのi行目とのxorをとる。
            for(int j = 0; j < M; j++){
                S[j] ^= matrix[idr[i]][j];
            }
        }
    }
    for(int j = 0; j < M; j++){
        if(S[j] != 0){
            ok = false;
            break;
        }
    }
    ll ans = 1;
    for(int i = 0; i < zero; i++){
        ans *= 2;
        ans %= mod;
    }
    if(ok){
        cout << ans << endl;
    }
    else{
        cout << 0 << endl;
    }
}