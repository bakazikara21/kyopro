#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = (int)1e9;
int main(){
    int H,W;
    cin >> H >> W;

    vector<string> S(H);
    for(int i = 0; i < H; i++){
        cin >> S[i];
    }

    map<char,pair<int,int>> mp;
    vector<vector<pair<int,int>>> warp(26);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] != '.' and S[i][j] != '#'){
                int num = S[i][j]-'a';
                warp[num].push_back({i,j});
            }
        }
    }

    vector<vector<int>> dist(H,vector<int>(W,inf));
    dist[0][0] = 0;
    queue<pair<int,int>> que;
    que.push({0,0});
    vector<int> di = {0,-1,1,0};
    vector<int> dj = {1,0,0,-1};
    set<int> st;
    while(!que.empty()){
        int i = que.front().first;
        int j = que.front().second;
        que.pop();

        for(int k = 0; k < 4; k++){
            int ni = i+di[k];
            int nj = j+dj[k];

            if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
            if(S[ni][nj] == '#') continue;
            if(dist[ni][nj] != inf) continue;

            dist[ni][nj] = dist[i][j]+1;
            que.push({ni,nj});
        }
        if(S[i][j] != '.' and S[i][j] != '#'){
            int num = S[i][j]-'a';
            if(st.count(num)) continue;
            st.insert(num);
            for(auto [ni,nj] : warp[num]){
                if(ni == i and nj == j) continue;
                if(dist[ni][nj] != inf) continue;

                dist[ni][nj] = dist[i][j]+1;
                que.push({ni,nj});
            }
        }
    }
    if(dist[H-1][W-1] != inf){
        cout << dist[H-1][W-1] << endl;
    }else{
        cout << -1 << endl;
    }
}