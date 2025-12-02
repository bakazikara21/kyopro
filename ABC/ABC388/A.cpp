#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    ll sum = 0;
    for(int i = 0; i < N; i++){
        int id = lower_bound(A.begin(),A.end(),A[i]*2)-A.begin();
        sum += (ll)(N-id);
    }
    cout << sum << endl;
}