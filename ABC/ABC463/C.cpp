#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<pair<ll,ll>> LH(N);
    for(int i = 0; i < N; i++){
        ll H,L; cin >> H >> L;
        LH[i] = {L,H};
    }
    sort(LH.begin(),LH.end());
    vector<ll> mx(N);
    for(int i = N-1; i >= 0; i--){
        if(i == N-1){
            mx[i] = LH[i].second;
        }
        else{
            mx[i] = max(mx[i+1],LH[i].second);
        }
    }
    int Q; cin >> Q;
    for(int q = 0; q < Q; q++){
        ll T; cin >> T;
        int t = upper_bound(LH.begin(),LH.end(),make_pair(T+1,-1))-LH.begin();
        cout << mx[t] << endl;
    }
}
