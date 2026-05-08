#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int H,W; cin >> H >> W;
    if(H == 1) cout << W << endl;
    else if(W == 1) cout << H << endl;
    else cout << ((H+1)/2) * ((W+1)/2) << endl;
}