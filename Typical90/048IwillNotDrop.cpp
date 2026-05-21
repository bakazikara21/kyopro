#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;

int main(){
    int N,K; cin >> N >> K;
    vector<ll> list;
    for(int i = 0; i < N; i++){
        ll A,B; cin >> A >> B;
        list.push_back(B);
        list.push_back(A-B);
    }
    sort(list.rbegin(),list.rend());
    ll ans = 0;
    for(int k = 0; k < K; k++){
        ans += list[k];
    }
    cout << ans << endl;
}