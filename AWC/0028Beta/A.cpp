#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K; cin >> N >> K;
    int ans = 0;
    for(int i = 0; i < N; i++){
        int P; cin >> P;
        if(P >= K) ans += P;
    }
    cout << ans << endl;
}
