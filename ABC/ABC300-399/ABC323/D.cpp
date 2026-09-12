#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 2147483647;
// 
int main(){
    int N;
    cin >> N;

    map<ll,ll> mp;
    for(int i = 0; i < N; i++){
        // i番目のスライムのサイズS[i]
        ll S,C;
        cin >> S >> C;
        mp[S] += C;
    }

    ll ans = 0;
    for(auto [key,c] : mp){
        ans += (c%2);
        ll s = key;
        mp[s] = 0;
        while(c >= 1){
            mp[s] += (c%2);
            s *= 2;
            c /= 2;
        }
    }
    cout << ans << endl;
}