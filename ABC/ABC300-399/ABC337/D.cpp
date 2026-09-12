#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int H,W,K;
    cin >> H >> W >> K;

    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    // 行と列は合計 H+W 通りある
    // imos法なのか-> x が邪魔
    // 差分をとるか、累積和を事前に計算するか
    int ans = H*W+1;
    for(int i = 0; i < H; i++){
        int maru = 0, need = 0;
        for(int j = 0; j < W; j++){
            // i行目において最小の必要個数を求める
            if(S[i][j] == 'x'){
                need = 0;
                maru = 0;
            }
            else if(maru+need < K){
                // K個連続していないとき
                if(S[i][j] == 'o'){
                    maru++;
                }
                if(S[i][j] == '.'){
                    need++;
                }
            }
            else {
                // maru+need >= Kのとき、差分をとろう
                if(S[i][j-K] == 'o'){
                    maru--;
                }
                if(S[i][j-K] == '.'){
                    need--;
                }

                if(S[i][j] == 'o'){
                    maru++;
                }
                if(S[i][j] == '.'){
                    need++;
                }
            }
            if(maru+need >= K){
                ans = min(ans,need);
            }
        }
    }
    for(int j = 0; j < W; j++){
        int maru = 0, need = 0;
        for(int i = 0; i < H; i++){
            // i行目において最小の必要個数を求める
            if(S[i][j] == 'x'){
                need = 0;
                maru = 0;
            }
            else if(maru+need < K){
                // K個連続していないとき
                if(S[i][j] == 'o'){
                    maru++;
                }
                if(S[i][j] == '.'){
                    need++;
                }
            }
            else {
                // maru+need >= Kのとき、差分をとろう
                if(S[i-K][j] == 'o'){
                    maru--;
                }
                if(S[i-K][j] == '.'){
                    need--;
                }

                if(S[i][j] == 'o'){
                    maru++;
                }
                if(S[i][j] == '.'){
                    need++;
                }
            }
            if(maru+need >= K){
                ans = min(ans,need);
            }
        }
    }

    if(ans == H*W+1){
        cout << -1 << endl;
    }
    else cout << ans << endl;
}
