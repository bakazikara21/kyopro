#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M,T; cin >> N >> M >> T;
    int sum = 0;
    for(int i = 0; i < N; i++){
        int A; cin >> A;
        sum += max(0,T-A);
    }
    if(sum > M) cout << -1 << endl;
    else cout << sum << endl;
}
