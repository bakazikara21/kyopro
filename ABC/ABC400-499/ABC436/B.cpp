#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;

    vector<vector<int>> A(N,vector<int>(N));
    int r = 0;
    int c = (N-1)/2;
    int k = 1;
    A[r][c] = k;
    for(int i = 0; i < N*N-1; i++){
        k++;
        int R = (r-1)%N;
        int C = (c+1)%N;

        if(R < 0) R += N;
        if(A[R][C] == 0){
            r = R;
            c = C;
            A[r][c] = k;
        }else{
            r = (r+1)%N;
            A[r][c] = k;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}