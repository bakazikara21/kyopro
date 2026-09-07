#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<ll> A(N),B(N),W(N);
    for(ll &a : A) cin >> a;
    for(ll &b : B) cin >> b;
    bool ok = false;
    for(int i = 0; i < N; i++){
        if(A[i]-B[i] > 0){
            ok = true;
            W[i] = INF;
        }
        else W[i] = 1;
    }
    if(ok){
        cout << "Yes" << endl;
        for(int i = 0; i < N; i++){
            cout << W[i] << " ";
        }
        cout << endl;
    }
    else cout << "No" << endl;
}
