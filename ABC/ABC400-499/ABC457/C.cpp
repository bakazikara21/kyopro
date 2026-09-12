#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ll N,K; cin >> N >> K;
    vector<vector<ll>> A(N);
    vector<ll> L(N);
    for(int i = 0; i < N; i++){
        cin >> L[i];
        for(int j = 0; j < L[i]; j++){
            int a; cin >> a;
            A[i].push_back(a);
        }
    }
    vector<ll> C(N);
    for(int i = 0; i < N; i++) cin >> C[i];
    int i = 0;
    ll sum = 0;
    while(sum < K){
        sum += L[i]*C[i];
        i++;
    }
    i--;
    // A[i]のどれか A[i][8]とか
    ll rest = (sum - K)%L[i];
    cout << A[i][L[i]-1-rest] << endl;
}
