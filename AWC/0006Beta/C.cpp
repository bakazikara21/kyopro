#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M,D;
    cin >> N >> M >> D;
    ll ans = 0;
    for(int i = 0; i < N; i++){
        int T;
        cin >> T;
        if(T <= M) continue;
        if((T-M)%D == 0){
            ans += (ll)(T-M)/D;
        }
        else ans += (ll)(T-M)/D + 1;
    }
    cout << ans << endl;
}
