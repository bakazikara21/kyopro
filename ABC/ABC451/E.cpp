#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<vector<int>> A(N,vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++) cin >> A[i][j];
    }
}
