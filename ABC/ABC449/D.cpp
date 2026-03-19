#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ll L,R,D,U; cin >> L >> R >> D >> U;
    ll ans = 0;
    ll left,right;
    for(ll x = L; x <= R; x++){
        // xを固定したときに(x,y)が黒であるyの個数をO(1)で求める

        // 1. |x| >= |y|のとき、-|x| <= y <= |x| and D <= y <= U
        ll X = abs(x);
        if((X%2) == 0){
            left = max(D,-X);
            right = min(U,X);
            if(right >= left) ans += right-left+1;
        }
    }
    for(ll y = D; y <= U; y++){
        // 2. |x| < |y|のとき、-|y| < x < |y| and L <= x <= R
        ll Y = abs(y);
        if((Y%2) == 0){
            left = max(L,-Y+1);
            right = min(R,Y-1);
            if(right >= left) ans += right-left+1;
        }
    }
    cout << ans << endl;
}