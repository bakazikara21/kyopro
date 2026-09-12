#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int H,W; cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];
  
    vector<int> di = {1,-1,0,0};
    vector<int> dj = {0,0,1,-1};
    queue<pair<int,int>> que;
    int cnt = 0;
    vector<vector<int>> num(H,vector<int>(W,-1));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '#') continue;
            if(num[i][j] >= 0) continue;
            cnt++;
            que.push({i,j});
            while(!que.empty()){
                auto [x,y] = que.front(); que.pop();
                if(num[x][y] >= 0) continue;
                num[x][y] = cnt;
                for(int k = 0; k < 4; k++){
                    int nx = x+di[k];
                    int ny = y+dj[k];
                    if(nx < 0 or nx >= H or ny < 0 or ny >= W) continue;
                    if(S[nx][ny] == '#' or num[nx][ny] >= 0) continue;
                    que.push({nx,ny});
                }
            }
        }
    }
    set<int> st;
    for(int i = 0; i < H; i++){
        int w = 0;
        int w2 = W-1;
        if(S[i][w] == '.') st.insert(num[i][w]);
        if(S[i][w2] == '.') st.insert(num[i][w2]);
        //cout << "num = " << num[i][w] << " " << num[i][w2] << endl;
    }
    for(int j = 0; j < W; j++){
        int h = 0;
        int h2 = H-1;
        if(S[h][j] == '.') st.insert(num[h][j]);
        if(S[h2][j] == '.') st.insert(num[h2][j]);
        //cout << "num = " << num[h]
    }
    cout << cnt - (int)st.size() << endl;
    //cout << "cnt = " << cnt << endl;
}
