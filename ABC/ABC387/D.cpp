#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = (int)1e8;
int main(){
    int H,W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++){
        cin >> S[i];
    }
    int sx,sy,gx,gy;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == 'S'){
                sx = i;
                sy = j;
            }
            if(S[i][j] == 'G'){
                gx = i;
                gy = j;
            }
        }
    }
    vector<vector<vector<int>>> grid(H,vector<vector<int>>(W,vector<int>(2,inf)));
    grid[sx][sy][0] = 0;    // 0が縦から入るとき
    grid[sx][sy][1] = 0;    // 1が横から入るとき
    vector<int> di = {1,-1,0,0};
    vector<int> dj = {0,0,1,-1};
    queue<tuple<int,int,int>> que;
    que.push({sx,sy,0});
    while(!que.empty()){
        auto [i,j,d] = que.front(); que.pop();

        if(d == 0){
            for(int k = 0; k < 4; k++){
                int ni = i + di[k];
                int nj = j + dj[k];
    
                if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
                if(S[ni][nj] == '#') continue;
                if(grid[ni][nj][k/2] < inf) continue;
    
                grid[ni][nj][k/2] = grid[i][j][1-k/2]+1;
                if(k >= 2){
                    // 次は縦の移動のみ
                    que.push({ni,nj,1});
                }
                else que.push({ni,nj,-1});
            }
        }
        if(d == 1){
            // 縦の移動のみ
            for(int k = 0; k < 2; k++){
                int ni = i + di[k];
                int nj = j + dj[k];
    
                if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
                if(S[ni][nj] == '#') continue;
                if(grid[ni][nj][k/2] < inf) continue;
    
                grid[ni][nj][k/2] = grid[i][j][1-k/2] +1;
                // 次は横の移動のみ
                que.push({ni,nj,-1});
            }
        }
        if(d == -1){
            // 横の移動のみ
            for(int k = 2; k < 4; k++){
                int ni = i + di[k];
                int nj = j + dj[k];
    
                if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
                if(S[ni][nj] == '#') continue;
                if(grid[ni][nj][k/2] < inf) continue;
    
                grid[ni][nj][k/2] = grid[i][j][1-k/2] +1;
                // 次は縦の移動のみ
                que.push({ni,nj,1});
            }
        }
    }
    if(grid[gx][gy][0] == inf and grid[gx][gy][1] == inf){
        cout << -1 << endl;
    }
    else cout << min(grid[gx][gy][0],grid[gx][gy][1]) << endl;

    /*
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    */
}