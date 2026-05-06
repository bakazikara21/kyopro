#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;
int main(){
    string S; cin >> S;
    int N = (int)S.size();

    ll r = 0;
    ll ans = 0;
    for(ll l = 0; l < N; l++){
        // 左端固定で右端をどれだけ伸ばせるか
        r = max(r,l);
        while(r+1 < N and S[r] != S[r+1]){
            r++;
        }
        ans += (r-l+1);
        //cout << "l = " << l << " add = " << (r-l+1) << endl;
    }
    cout << ans%mod << endl;
}
