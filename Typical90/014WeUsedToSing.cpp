#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = (int)1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<ll> A(N),B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    ll ans = 0;
    for(int i = 0; i < N; i++) ans += abs(A[i]-B[i]);
    cout << ans << endl;
}
