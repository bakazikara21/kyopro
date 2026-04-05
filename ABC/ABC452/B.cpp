#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int H,W; cin >> H >> W;
    vector<vector<char>> S(H,vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(i == 0 or i == H-1 or j == 0 or j == W-1){
                S[i][j] = '#';
            }
            else S[i][j] = '.';
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << S[i][j];
        }
        cout << endl;
    }
}
