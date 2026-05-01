#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int H,W; cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    int si,sj,gi,gj;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == 'S'){
                si = i;
                sj = j;
            }
            if(S[i][j] == 'G'){
                gi = i;
                gj = j;
            }
        }
    }
    // 下が0, 上が1, 右が2, 左が3
    vector<int> di = {1,-1,0,0};
    vector<int> dj = {0,0,1,-1};

    vector<vector<vector<bool>>> used(H,vector<vector<bool>>(W,vector<bool>(4,false)));
    vector<int> ans;
    bool finish = false;
    auto dfs = [&](auto self, int i, int j, int d)->void{
        // 座標(i,j), 入ってきた方向d
        if(i == gi and j == gj and !finish){
            cout << "Yes" << endl;
            int N = (int)ans.size();
            for(int i = 0; i < N; i++){
                if(ans[i] == 0){
                    cout << "D";
                }
                if(ans[i] == 1){
                    cout << "U";
                }
                if(ans[i] == 2){
                    cout << "R";
                }
                if(ans[i] == 3){
                    cout << "L";
                }
            }
            cout << endl;
            finish = true;
            return;
        }
        if(d >= 0) used[i][j][d] = true;
        if(finish) return;
        for(int k = 0; k < 4; k++){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
            if(S[ni][nj] == '#') continue;
            if(used[ni][nj][k]) continue;

            if(S[i][j] == 'o'){
                if(k != d) continue;
                ans.push_back(k);
                self(self,ni,nj,k);
                ans.pop_back();
            }
            else if(S[i][j] == 'x'){
                if(k == d) continue;
                ans.push_back(k);
                self(self,ni,nj,k);
                ans.pop_back();
            }
            else {
                ans.push_back(k);
                self(self,ni,nj,k);
                ans.pop_back();
            }
            if(finish) return;
        }
        //if(d >= 0) used[i][j][d] = false;
    };
    dfs(dfs,si,sj,-1);
    if(!finish){
        cout << "No" << endl;
    }
}
