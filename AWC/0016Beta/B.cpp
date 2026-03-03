#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,T; cin >> N >> T;
    ll sum = 0;
    for(int i = 0; i < N; i++){
        ll A,C; cin >> A >> C;
        if(A >= T) continue;
        sum += (T-A)*C;
    }
    cout << sum << endl;
}
