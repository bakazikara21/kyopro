#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;

int main(){
    int H,W; cin >> H >> W;
    vector<vector<vector<int>>> ans(H,vector<vector<int>>(W,vector<int>(4,inf)));
    int sx,sy; cin >> sx >> sy; sx--; sy--;
    int gx,gy; cin >> gx >> gy; gx--; gy--;
    for(int k = 0; k < 4; k++) ans[sx][sy][k] = 0;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    vector<int> di = {1,-1,0,0};
    vector<int> dj = {0,0,1,-1};

    // {i,j,dir}のdeque -> 0,1bfsってやつ
    deque<tuple<int,int,int>> dq;
    dq.push_back({sx,sy,0});
    dq.push_back({sx,sy,1});
    dq.push_back({sx,sy,2});
    dq.push_back({sx,sy,3});
    while(!dq.empty()){
        auto [i,j,dir] = dq.front(); dq.pop_front();
        int num = ans[i][j][dir];
        if(i == gx and j == gy) continue;
        for(int k = 0; k < 4; k++){
            int ni = i + di[k];
            int nj = j + dj[k];
            if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
            if(S[ni][nj] == '#') continue;

            int pls = 1 - (k == dir);   // ==なら0, !=なら1
            
            if(ans[ni][nj][k] <= num+pls) continue;
            ans[ni][nj][k] = num+pls;
            if(pls == 1) dq.push_back({ni,nj,k});   // 曲がる回数が増えるなら最後尾に
            if(pls == 0) dq.push_front({ni,nj,k});  // 曲がる回数が増えないなら先頭に
        }
    }
    int anss = inf;
    for(int k = 0; k < 4; k++){
        anss = min(anss,ans[gx][gy][k]);
    }
    cout << anss << endl;
}