#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ll N,M,S; cin >> N >> M >> S;
    vector<ll> D(N);
    for(int i = 0; i < N; i++){
        cin >> D[i];
    }
    bool flag = false;
    vector<pair<ll,ll>> query(M);
    for(int i = 0; i < M; i++){
        cin >> query[i].first >> query[i].second;
        query[i].first--;
    }
    sort(query.begin(),query.end());
    ll j = 0,P,R;
    if(M > 0){
        P = query[j].first;
        R = query[j].second;
    }
    for(int i = 0; i < N; i++){
        if(flag){
            S = S-2*D[i];
        }
        else S = S-D[i];
        if(S <= 0) flag = true;
        if(P == i){
            S += R;
            j++;
            if(M > j){
                P = query[j].first;
                R = query[j].second;
            }
        }
    }
    cout << S << endl;
}
