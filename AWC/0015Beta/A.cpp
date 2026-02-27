#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N = 7;
    vector<int> A(N),B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans += A[i]*B[i];
    }
    cout << ans << endl;
}
