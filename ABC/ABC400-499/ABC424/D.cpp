#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

// 無理
int main(){
    int T; cin >> T;
    vector<pair<int,int>> can = {
        {1,1},
        {1,3},
        {1,5},
        {3,1},
        {3,3},
        {3,5},
        {5,1},
        {5,3},
        {5,5},
    };
    // 9近傍
    vector<int> di = {-1,-1,0,0};
    vector<int> dj = {-1,0,-1,0};

    vector<int> dx = {1,1,0,0};
    vector<int> dy = {1,0,1,0};
    for(int t = 0; t < T; t++){
        int H,W; cin >> H >> W;
        vector<string> S(H);
        for(int i = 0; i < H; i++) cin >> S[i];

        int ans = 0;    // ans <= 9;
        for(auto [i,j] : can){
            if(i >= H or j >= W) continue;

            bool ok = false;    // 2*2の黒がひとつでもあればtrue
            for(int k = 0; k < 4; k++){
                // 候補となる2*2の左上の座標
                int ni = i+di[k];
                int nj = j+dj[k];
                if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
                
                bool flag = true;  // ひとつでも白マスがあればfalse;
                for(int m = 0; m < 4; m++){
                    int nx = ni+dx[m];
                    int ny = nj+dy[m];
                    if(nx < 0 or nx >= H or ny < 0 or ny >= W){
                        flag = false;
                        continue;
                    }
                    
                    if(S[nx][ny] == '.') flag = false;
                }
                if(flag){
                    // ひとつも白マスがないとき
                    ok = true;
                }
            }
            if(ok){
                ans++;
            }
        }
        cout << ans << endl;
    }
}
