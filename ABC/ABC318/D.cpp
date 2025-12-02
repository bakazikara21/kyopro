#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;

    vector<vector<ll>> D(N,vector<ll>(N));
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            ll d;
            cin >> d;
            D[i][j] = d;
            D[j][i] = d;
        }
    }
    // N / 2 本選ぶ
}