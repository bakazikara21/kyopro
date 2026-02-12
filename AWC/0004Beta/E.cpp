#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; ll K;
    cin >> N >> K;
    vector<ll> A(N),presum(N+1);
    vector<pair<ll,int>> keys(N+1);
    keys[0] = {0,0};
    ll ans = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        presum[i+1] = presum[i]+A[i];
        keys[i+1] = {presum[i+1],i+1};
    }
    sort(keys.begin(),keys.end());
    for(int l = 0; l <= N; l++){
        // 左端固定
        auto itrR = upper_bound(keys.begin(),keys.end(),make_pair(presum[l]+K,inf));
        auto itrL = lower_bound(keys.begin(),keys.end(),make_pair(presum[l]+K,l+1));
        ans += (itrR - itrL);
        //cout << "left = " << l << " differ = " << (itrR - itrL) << endl;
    }
    cout << ans << endl;
}
