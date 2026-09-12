#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;

    vector<vector<int>> grid(N,vector<int>(N,0));
    grid[N/2][N/2] = 0;

    vector<int> di = {0,1,0,-1};
    vector<int> dj = {1,0,-1,0};

    int i = 0;
    int j = 0;
    int dir = 0;
    int num = 1;
    while(1){
        if(i == N/2 and j == N/2) break;

        grid[i][j] = num;

        int ni = i+di[dir];
        int nj = j+dj[dir];
        if(ni >= N or nj >= N or ni < 0 or nj < 0){
            dir = (dir+1)%4;
        }
        else if(grid[ni][nj] > 0){
            dir = (dir+1)%4;
        }
        i += di[dir];
        j += dj[dir];
        //cout << "i = " << i << " j = " << j << endl;
        num++;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == N/2 and j == N/2){
                cout << 'T' << " ";
            }
            else{
                cout << grid[i][j] << " ";
            }
        }
        cout << endl;
    }
}
