#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.rbegin(),A.rend());
    cout << A[0]+A[1] << endl;
}
