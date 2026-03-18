#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int H,W,Q; cin >> H >> W >> Q;
    for(int q = 0; q < Q; q++){
        int num; cin >> num;
        if(num == 1){
            int R; cin >> R;
            cout << W*R << endl;
            H -= R;
        }
        else {
            int C; cin >> C;
            cout << H*C << endl;
            W -= C;
        }
    }
}
