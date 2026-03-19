#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const int MAX = 10000;
int main(){
    ll N,A,B,C; cin >> N >> A >> B >> C;
    int ans = inf;
    for(int b = 0; b < MAX; b++){
        for(int c = 0; b+c < MAX; c++){
            ll target = N-(b*B+c*C);
            if(target < 0) continue;
            if((target%A) != 0) continue;
            int a = target/A;
            ans = min(ans,a+b+c);
        }
    }
    cout << ans << endl;
}