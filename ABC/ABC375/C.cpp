#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void rotation(vector<string> &A, vector<string> &grid, int first, int last, int N){
    // 外側だけ (first+1)*90度時計回りに回転させる
    if((first+1)%4 == 1){
        for(int i = first; i <= last; i++){
            grid[first][N-1-i] = A[i][first];
            grid[last][N-1-i] = A[i][last];
        }
        for(int i = first; i <= last; i++){
            grid[i][last] = A[first][i];
            grid[i][first] = A[last][i];
        }
    }
    if((first+1)%4 == 2){
        for(int i = first; i <= last; i++){
            grid[N-1-i][N-1-first] = A[i][first];
            grid[N-1-i][N-1-last] = A[i][last];
        }
        for(int i = first; i <= last; i++){
            grid[N-1-first][N-1-i] = A[first][i];
            grid[N-1-last][N-1-i] = A[last][i];
        }
    }
    if((first+1)%4 == 3){
        for(int i = first; i <= last; i++){
            grid[N-1-first][i] = A[i][first];
            grid[N-1-last][i] = A[i][last];
        }
        for(int i = first; i <= last; i++){
            grid[N-1-i][first] = A[first][i];
            grid[N-1-i][last] = A[last][i];
        }
    }
}
int main(){
    int N;
    cin >> N;
    vector<string> A(N),grid(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        grid[i] = A[i];
    }
    for(int i = 0; i < N/2; i++){
        if((i+1)%4 == 0) continue;
        rotation(A,grid,i,N-1-i,N);
    }
    for(int i = 0; i < N; i++){
        cout << grid[i] << endl;
    }
}
