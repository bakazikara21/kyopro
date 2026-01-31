#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; ll T;
    cin >> N >> T;
    if(N == 0){
        cout << T << endl;
        return 0;
    }
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    ll ans = A[0];
    ll now = A[0];
    while(1){
        int t = lower_bound(A.begin(),A.end(),now+100)-A.begin();
        if(t == N){
            ans += T - (now+100);
            cout << ans << endl;
            return 0;
        }
        ans += A[t] - (now+100);
        now = A[t];
        if(now + 100 > T){
            cout << ans << endl;
            return 0;
        }
    }
}
