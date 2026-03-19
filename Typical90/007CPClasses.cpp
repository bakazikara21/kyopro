#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)10007; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(),A.end());
    int Q; cin >> Q;
    ll ans = 0;
    for(int q = 0; q < Q; q++){
        ll B; cin >> B;
        int t = lower_bound(A.begin(),A.end(),B)-A.begin();
        if(t == N){ 
            cout << B-A[N-1] << endl;
        }
        else if(t == 0){
            cout << A[0]-B << endl;
        }
        else cout << min(A[t]-B,B-A[t-1]) << endl;
    }
}
