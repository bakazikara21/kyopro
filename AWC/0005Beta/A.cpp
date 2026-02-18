#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ll ans = 0;
    ll N,K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        ll P;
        cin >> P;
        if((P%K) == 0){
            ans += P;
        }
    }
    cout << ans << endl;
}
