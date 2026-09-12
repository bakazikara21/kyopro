#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ll N,M;
    cin >> N >> M;

    ll ans = M*(M-1)/2; // 平行な辺の総数を引き算すればよい
    vector<ll> mod(N);
    for(int i = 0; i < M; i++){
        int A,B;
        cin >> A >> B;
        mod[(A+B)%N]++;
    }
    for(int i = 0; i < N; i++){
        ans -= mod[i]*(mod[i]-1)/2;
    }
    cout << ans << endl;
}
