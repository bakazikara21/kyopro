#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N,X,Y;
    cin >> N >> X >> Y;

    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(),A.end());
    ll W = Y*A[0];
    // Xa+Yb = W;

    ll sum = 0;
    for(int i = 0; i < N; i++){
        if((W-X*A[i]) < 0 or (W-X*A[i])%(Y-X) != 0){
            cout << -1 << endl;
            return 0;
        }else{
            sum += (W-X*A[i]) / (Y-X);
        }
    }
    cout << sum << endl;
}
