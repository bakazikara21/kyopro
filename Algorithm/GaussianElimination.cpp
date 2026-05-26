#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;

void GaussianElimination(vector<vector<ll>> &matrix){
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
        // matrix[row][col] != 0のとき
        // まずrow行目をすべてmatrix[row][col]で割り算する
        ll divisor = matrix[row][col];
        for(int j = 0; j < M; j++){
            matrix[row][j] /= divisor;
        }

        // 続いて、col列目をすべて0にする。ただし、row行目を除く
        for(int r = 0; r < N; r++){
            if(r == row) continue;

            if(matrix[r][col] != 0){
                // col列目はすべて0にする！
                ll rate = matrix[r][col];
                for(int j = 0; j < M; j++){
                    matrix[r][j] -= matrix[row][j] * rate;
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