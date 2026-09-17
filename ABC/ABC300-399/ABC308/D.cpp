#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int H,W; cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];
    if(S[0][0] != 's'){
        cout << "No" << endl;
        return 0;
    }
    vector<vector<bool>> visited(H,vector<bool>(W,false));
    vector<int> di = {1,-1,0,0};
    vector<int> dj = {0,0,1,-1};
    queue<tuple<int,int,int>> que;
    que.push({0,0,0});
    visited[0][0] = true;
    while(!que.empty()){
        auto [i,j,k] = que.front(); que.pop();
        int nk = (k+1)%5;
        char nc = "snuke"[nk];
        for(int t = 0; t < 4; t++){
            int ni = i+di[t];
            int nj = j+dj[t];
            if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
            if(S[ni][nj] != nc) continue;
            if(visited[ni][nj]) continue;
            visited[ni][nj] = true;
            que.push({ni,nj,nk});
        }
    }
    if(visited[H-1][W-1]){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}
