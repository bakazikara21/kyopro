#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;

int main(){
    int H,W; cin >> H >> W;
    vector<vector<int>> P(H,vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> P[i][j];
    }
    // Hに関してbit全探索して、それに対してWをうまく確定させる
    int hmax = (1<<H);
    int ans = 0;
    for(int h = 1; h < hmax; h++){
        int cntH = 0;
        vector<int> idh;
        for(int bit = 0; bit < H; bit++){
            if((h >> bit) & 1){
                // bit番目を使うとき
                cntH++;
                idh.push_back(bit);
            }
        }
        int id = (int)idh.size();
    
        vector<int> cntW(H*W+1);
        for(int w = 0; w < W; w++){
            bool ok = true;
            // w列において、選んだ行すべての整数が一致しているならcnt++;
            for(int i = 0; i+1 < id; i++){
                if(P[idh[i]][w] != P[idh[i+1]][w]){
                    ok = false;
                    break;
                }
            }
            if(ok) cntW[P[idh[0]][w]]++;    // 整数P[idh[0]][w]のみの列の個数をインクリメント
        }
        // if(target == 2){
        //     cout << "hmask = " << h << " cntH = " << cntH << " cntW = " << cntW << endl;
        // }
        int cntWmax = 0;
        for(int i = 1; i <= H*W; i++){
            cntWmax = max(cntWmax,cntW[i]);
        }
        ans = max(ans,cntH * cntWmax);
    
    }
    cout << ans << endl;
}