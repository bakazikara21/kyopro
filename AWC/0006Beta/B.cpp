#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K; ll T;
    cin >> N >> K >> T;
    ll ans = 0;
    for(int i = 0; i < N; i++){
        ll D,R;
        cin >> D >> R;
        if(R >= D*K){
            ans += R;
        }
    }
    if(ans >= T){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}
