#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N = 9;
    vector<vector<int>> A(N,vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> A[i][j];
    }
    vector<int> cnt(N+1);
    bool ok = true;
    for(int i = 0; i < N; i++){
        // 各行について
        for(int j = 0; j < N; j++){
            cnt[A[i][j]] += 1;
        }
        for(int j = 0; j < N; j++){
            if(cnt[j+1] != 1){
                ok = false;
                break;
            }
            cnt[j+1] = 0;
        }
        if(ok == false) break;
    }
    for(int j = 0; j < N; j++){
        // 各列について
        for(int i = 0; i < N; i++){
            cnt[A[i][j]] += 1;
        }
        for(int i = 0; i < N; i++){
            if(cnt[i+1] != 1){
                ok = false;
                break;
            }
            cnt[i+1] = 0;
        }
        if(ok == false) break;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            // 各行列B_ijに対して
            for(int m = 0+3*i; m < 3+3*i; m++){
                for(int n = 0+3*j; n < 3+3*j; n++){
                    cnt[A[m][n]] += 1;
                }
            }
            for(int i = 0; i < N; i++){
                if(cnt[i+1] != 1){
                    ok = false;
                    break;
                }
                cnt[i+1] = 0;   // 初期化
            }
            if(ok == false) break;
        }
    }
    if(ok){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
