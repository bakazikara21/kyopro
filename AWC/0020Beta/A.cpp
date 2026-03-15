#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    ll sum = 0;
    for(int i = 0; i < N; i++){
        ll A; cin >> A;
        sum += A;
    }
    if((sum%N) == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
