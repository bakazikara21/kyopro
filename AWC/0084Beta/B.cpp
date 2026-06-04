#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int H,W; cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];
    
    /*
        白マスと黒マスが八近傍にあるならば、
        その白マスと黒マスは交互に白->黒->白->...を永遠に繰り返すことが確定する。
        ->だからなに？
    */
}
