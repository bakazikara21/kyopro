#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int H,W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    vector<int> di = {-1,0,0,1};
    vector<int> dj = {0,1,-1,0};
    vector<vector<bool>> used(H,vector<bool>(W,false));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '#'){
                // i,jに磁石が置いてあるならば
                for(int k = 0; k < 4; k++){
                    int ni = i+di[k];
                    int nj = j+dj[k];
                    if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
                    if(S[ni][nj] == '#') continue;
                
                    S[ni][nj] = 'x';    // 四近傍を行き止まりとする
                }
                used[i][j] = true;
            }
        }
    }
    // 以下、連結成分の最大値を求める
    set<pair<int,int>> st;
    auto dfs = [&](auto self, int i, int j)->int{
        int cnt = 0;
       
        if(S[i][j] == 'x'){
            st.insert({i,j});
            return 1;
        }
        used[i][j] = true;
        for(int k = 0; k < 4; k++){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
            if(S[i][j] == '#') continue;
            if(used[ni][nj] == true) continue;
            if(st.count({ni,nj})) continue;

            cnt += self(self,ni,nj);
        }
        return cnt+1;
    };
    int ans = 1;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '.' and used[i][j] == false){
                ans = max(ans,dfs(dfs,i,j));
            }
            st.clear();
        }
    }
    cout << ans << endl;
}