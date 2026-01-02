#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    ll mini = (ll)1e18;
    for(int i = 0; i < N; i++){
        ll a;
        cin >> a;
        if(i == 0) A[i] = a;
        else A[i] = A[i-1]+a;
        
        mini = min(mini,A[i]);
    }   
    if(mini > 0) mini = 0;
    cout << A[N-1]-mini << endl;
}
