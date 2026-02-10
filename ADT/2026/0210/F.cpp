#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M;
    cin >> N >> M;
    vector<ll> A(N),B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    ll ans = INF;
    for(int i = 0; i < N; i++){
        // A[i]に対して、Bは高々2通りしかない
        int t = lower_bound(B.begin(),B.end(),A[i])-B.begin();

        if(t == M){
            ans = min(ans,abs(A[i]-B[t-1]));
        }
        else if(t == 0){
            ans = min(ans,abs(A[i]-B[t]));
        }
        else {
            ans = min(ans,abs(A[i]-B[t-1]));
            ans = min(ans,abs(A[i]-B[t]));
        }
    }
    cout << ans << endl;
}
