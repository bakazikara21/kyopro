#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int H,W,Q; cin >> H >> W >> Q;
    vector<pair<int,int>> query(Q);
    vector<char> X(Q);
    for(int q = 0; q < Q; q++){
        cin >> query[q].first >> query[q].second >> X[q];
    }
    vector<vector<char>> grid(H,vector<char>(W,'#'));
    for(int q = Q-1; q >= 0; q--){
        auto [R,C] = query[q];
        R--; C--;
        char x = X[q];
        if(grid[R][C] != '#') continue;
        for(int i = R; i >= 0; i--){
            for(int j = C; j >= 0; j--){
                if(grid[i][j] != '#') break;
                grid[i][j] = x;
            }
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(grid[i][j] == '#') grid[i][j] = 'A';
            cout << grid[i][j];
        }
        cout << endl;
    }
}
