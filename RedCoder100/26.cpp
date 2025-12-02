#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int m,n;
    cin >> m >> n;

    vector<vector<int>> grid(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // 1なら薄氷あり
            cin >> grid[i][j];
        }
    }
    //　各成分の要素数の最大値を求めよ
    vector<int> di = {0,-1,1,0};
    vector<int> dj = {1,0,0,-1};
  
    function<int(int,int,int)> dfs = [&](int i, int j, int num){
        for(int k = 0; k < 4; k++){
            int ni = i+di[k];
            int nj = j+dj[k];
            dfs(ni,nj,num+1);
        }
        return 1;
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 0) continue;

            // start = (i,j)
            dfs(i,j,0);
        }
    }
}