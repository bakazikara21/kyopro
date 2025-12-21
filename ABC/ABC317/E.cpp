#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = (int)1e8;
  const string direction = "v>^<";
  const vector<int> dx{1, 0, -1, 0};
  const vector<int> dy{0, 1, 0, -1};

int main(){
    int H,W;
    cin >> H >> W;
    vector<string> grid(H),regrid(H);
    for(int i = 0; i < H; i++){
        cin >> grid[i];
        regrid[i] = grid[i];
    }
    int si,sj,gi,gj;
    queue<pair<int,int>> que;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(grid[i][j] == '<' or
                grid[i][j] == '>' or
                grid[i][j] == 'v' or
                grid[i][j] == '^'){
                    que.push({i,j});
            }
            if(grid[i][j] == 'S'){
                si = i;
                sj = j;
            }
            if(grid[i][j] == 'G'){
                gi = i;
                gj = j;
            }
        }
    }
    while(!que.empty()){
        auto [i,j] = que.front(); que.pop();

        if(grid[i][j] == '<'){
            regrid[i][j] = '#';
            while(j-1 >= 0 and grid[i][j-1] == '.'){
                regrid[i][j-1] = '#';
                j--;
            }
        }
        if(grid[i][j] == '>'){
            regrid[i][j] = '#';
            while(j+1 < W and grid[i][j+1] == '.'){
                regrid[i][j+1] = '#';
                j++;
            }
        }

        if(grid[i][j] == '^'){
            regrid[i][j] = '#';
            while(i-1 >= 0 and grid[i-1][j] == '.'){
                regrid[i-1][j] = '#';
                i--;
            }
        }
        if(grid[i][j] == 'v'){
            regrid[i][j] = '#';
            while(i+1 < H and grid[i+1][j] == '.'){
                regrid[i+1][j] = '#';
                i++;
            }
        }
    }
    // regridに対してbfsして終わり
    vector<int> di = {0,-1,1,0};
    vector<int> dj = {1,0,0,-1};
    vector<vector<int>> visited(H,vector<int>(W,inf));
    que.push({si,sj});
    visited[si][sj] = 0;
    while(!que.empty()){
        auto [i,j] = que.front(); que.pop();

        for(int k = 0; k < 4; k++){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
            if(visited[ni][nj] < inf) continue;
            if(regrid[ni][nj] == '#') continue;

            visited[ni][nj] = visited[i][j] + 1;
            que.push({ni,nj});
        }
    }
    if(visited[gi][gj] < inf){
        cout << visited[gi][gj] << endl;
    }else{
        cout << -1 << endl;
    }
}