#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; ll R,T; cin >> N >> R >> T;
    vector<ll> P(N);
    for(int i = 0; i < N; i++){
        cin >> P[i];
        cout << min((ll)T/P[i],R) << " ";
    }
    cout << endl;
}
