#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int bit(ll x){
    int cnt = 0;
    while((x) > 0){
        x /= 10;
        cnt++;
    }
    return cnt;
}
int main(){
    int N,V; cin >> N >> V;
    ll sum = 0;
    vector<ll> D(N-1);
    for(int i = 0; i < N-1; i++) cin >> D[i];
    sum += D[0];
    bool ok = true;
    for(int i = 2; i <= N; i++){
        ll T; cin >> T;
        
        int tbit = bit(T);
        int vbit = bit(V);
        if(sum < T*V or 17 < tbit+vbit){
            ok = false;
            cout << i << " ";
        }
        sum += D[i-1];
    }
    if(ok) cout << -1;
    cout << endl;
}
