#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<ll> V(N);
    for(int i = 0; i < N; i++) cin >> V[i];
    ll sum = 0;
    sort(V.begin(),V.end());
    for(int i = 1; i < N; i++) sum += abs(V[i]-V[i-1]);
    cout << sum << endl;
}
