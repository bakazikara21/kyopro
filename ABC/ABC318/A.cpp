#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;

    vector<vector<int>> area(101,vector<int>(101));
    for(int i = 0; i < N; i++){
        int A,B,C,D;
        cin >> A >> B >> C >> D;

        if(A+1 <= 100) area[A+1][D] += 1;
        if(B+1 <= 100) area[B+1][D] -= 1;

        if(A+1 <= 100) area[A+1][C] -= 1;
        if(B+1 <= 100) area[B+1][C] += 1;
    }

    int S = 0;
    for(int i = 0; i <= 100; i++){
        for(int j = 2; j <= 100; j++){
            area[j][i] += area[j-1][i];
        }
    }

    for(int j = 1; j <= 100; j++){
        for(int i = 99; i >= 0; i--){
            area[j][i] += area[j][i+1];
        }
    }

    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(area[i][j] >= 1) S++;
        }
    }
    cout << S << endl;
}