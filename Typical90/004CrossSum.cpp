#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)10007; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H,W; cin >> H >> W;
    vector<vector<int>> A(H,vector<int>(W));
    vector<int> row(H),column(W);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
            row[i] += A[i][j];
            column[j] += A[i][j];
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << row[i]+column[j]-A[i][j] << " ";
        }
        cout << endl;
    }
}
