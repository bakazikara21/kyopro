#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K; cin >> N >> K;
    vector<pair<ll,ll>> med(N);
    ll sum = 0;
    for(int i = 0; i < N; i++){
        ll a,b; cin >> a >> b;
        med[i] = {a,b};
        sum += b;
    }
    if(sum <= K){
        cout << 1 << endl;
        return 0;
    }
    sort(med.begin(),med.end());
    for(int i = 0; i < N; i++){
        auto [a,b] = med[i];
        sum -= b;
        if(sum <= K){
            cout << a+1 << endl;
            return 0;
        }
    }
}
