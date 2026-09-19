#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<ll> A(N),sum(N+1);
    for(int i = 0; i < N; i++){
        ll a; cin >> a;
        A[i] = a;
        if(i > 0 and i%2 == 0)  sum[i] += sum[i-1] + A[i]-A[i-1];
        else if(i > 0) sum[i] += sum[i-1];
    }
    int Q; cin >> Q;
    for(int q = 0; q < Q; q++){
        ll left,right; cin >> left >> right;
        int tl = lower_bound(A.begin(),A.end(),left)-A.begin();
        int tr = lower_bound(A.begin(),A.end(),right)-A.begin();

        ll ans = 0;
        if(tl%2 == 1){
            // 区間のスタートを指しているとき
            // なにもしない
        }
        else{
            // 区間の終端を指しているとき
            ans += A[tl]-left;
        }

        if(tr%2 == 1){
            // 区間のスタートを指しているとき
            // なにもしない
        }
        else{
            // 区間の終端を指しているとき
            tr--;
            ans += right - A[tr];
        }

        ans += sum[tr] - sum[tl];
        cout << ans << endl;
    }
}
