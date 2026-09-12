#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int buble(vector<int> pos, int N){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        // i番目がiになるようにスワップする回数を返す関数
        if(pos[i] == i) continue;

        for(int j = i+1; j < N; j++){
            if(pos[j] == i){
                //swap(pos[i],pos[j]);
                for(int k = j-1; k >= i; k--){
                    cnt++;
                    swap(pos[k],pos[k+1]);
                }
                break;
            }
        }
    }
    return cnt;
}
int main(){
    int H,W;
    cin >> H >> W;

    vector<vector<ll>> A(H,vector<ll>(W)),B(H,vector<ll>(W)),copy(H,vector<ll>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> A[i][j];
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> B[i][j];
    }

    vector<int> row(H); // Bの行の並び順を順列全探索
    for(int i = 0; i < H; i++){
        row[i] = i;
    }
    vector<int> column(W); // Bの列の並び順を順列全探索
    for(int i = 0; i < W; i++){
        column[i] = i;
    }
    bool ok = false;
    int ans = 100;
    do{
        do{
            // Bの行と列の並び替えに対してA0,A1,A2...をぶつける
            bool able = true;
            for(int i = 0; i < H; i++){
                for(int j = 0; j < W; j++){
                    // A[i][j] == B[pos[i]][pos[j]]となるかを全探索
                    if(A[i][j] != B[row[i]][column[j]]){
                        able = false;
                        break;
                    }
                }
                if(able == false) break;
            }
            if(able){
                // 回数は?
                ok = true;
                ans = min(ans,buble(row,H)+buble(column,W));
            }
        }while(next_permutation(column.begin(),column.end()));
    }while(next_permutation(row.begin(),row.end()));

    if(ok == false){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
}
