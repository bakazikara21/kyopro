#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int H,W,K;
    cin >> H >> W >> K;
    char c1,c2; cin >> c1 >> c2;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '#') S[i][j] = c1;
            else S[i][j] = c2;
        }
    }
    for(int i = 0; i < H; i++){
        int cnti = 0;
        while(cnti < K){
            for(int j = 0; j < W; j++){
                int cntj = 0;
                while(cntj < K){
                    cout << S[i][j];
                    cntj++;
                }
            }
            cnti++;
            cout << endl;
        }
    }
}
