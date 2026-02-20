#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N;
    cin >> N;
    ll ans = 0;
    ll dif = INF;
    for(int i = 0; i < N; i++){
        ll D; cin >> D;
        if(D > dif){
            ans += D/2;
        }
        else ans += D;
        dif = D;
    }    
    cout << ans << endl;
}
