#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; ll C; cin >> N >> M >> C;
    vector<ll> A(N),B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    sort(A.rbegin(),A.rend());
    sort(B.rbegin(),B.rend());
    ll cnt = 0;
    int id = 0;
    for(int i = 0; i < N; i++){
        while(id < M and A[i] < B[id]){
            id++;
        }
        if(id < M and A[i] >= B[id]){
            cnt++;
            id++;
        }
    }
    cout << cnt * C << endl;
}
