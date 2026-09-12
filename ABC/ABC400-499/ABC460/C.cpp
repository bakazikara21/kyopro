#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    vector<ll> A(N),B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    sort(A.rbegin(),A.rend());
    sort(B.rbegin(),B.rend());
    int b = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        while(b < M and B[b] > 2*A[i]){
            b++;
        }
        if(b < M and B[b] <= 2*A[i]){
            cnt++;
            b++;
        }
    }
    cout << cnt << endl;
}
