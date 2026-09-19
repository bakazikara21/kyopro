#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int H,W; cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    int xmin = inf,ymin = inf,xmax = 0,ymax = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '#'){
                xmin = min(xmin,i);
                ymin = min(ymin,j);
                xmax = max(xmax,i);
                ymax = max(ymax,j);
            }
        }
    }
    for(int i = xmin; i <= xmax; i++){
        for(int j = ymin; j <= ymax; j++){
            if(S[i][j] == '.'){
                cout << i+1 << " " << j+1 << endl;
                return 0;
            }
        }
    }
}
