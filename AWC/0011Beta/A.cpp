#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M,S,T;
    cin >> N >> M >> S >> T;
    if(S > T) swap(S,T);
    vector<pair<ll,ll>> PV(M);
    for(int i = 0; i < M; i++){
        cin >> PV[i].first >> PV[i].second;
    }
    sort(PV.begin(),PV.end());
    ll ans = 0;
    auto itr = lower_bound(PV.begin(),PV.end(),make_pair(S,-1));
    auto itrend = upper_bound(PV.begin(),PV.end(),make_pair(T,INF));
    while(itr != itrend){
        ans += itr->second;
        itr++;
    }
    cout << ans << endl;
}
