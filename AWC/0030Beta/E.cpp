#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    int M = 1000000;
    vector<ll> cnt(M+1);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        cnt[A[i]]++;
    }

    ll ans = 0;
    for(ll i = 1; i <= M; i++){
        if(i == 1) ans = max(ans,(ll)N);
        else {
            // 調和級数の計算量O(MlogM)
            ll cn = 0;
            for(ll j = 1; i*j <= M; j++){
                cn += cnt[i*j];
            }
            ans = max(ans,cn*i);
        }
    }
    cout << ans << endl;
}
