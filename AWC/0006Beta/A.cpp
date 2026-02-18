#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,L,W;
    cin >> N >> L >> W;
    int ans = 0;
    for(int i = 0; i < N; i++){
        int D;
        cin >> D;
        if(D >= L-W and D <= L+W) ans++;
    }
    cout << ans << endl;
}
