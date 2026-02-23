#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; ll K; cin >> N >> K;
    ll ans = 0,cnt = 0;
    for(int i = 0; i < N; i++){
        ll A; cin >> A;

        if((A&K) == A){
            ans |= A;
            cnt++;
        }
    }
    if(ans == K and cnt > 0) cout << cnt << endl;
    else cout << -1 << endl;
}
