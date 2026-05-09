#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ll N,K; cin >> N >> K;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // 最小値の最大化は二分探索だが、
    // minA[i] = Xがありうるのか二分探索
    ll l = 0, r = INF+1;
    ll X = (r+l)/2;
    while((r-l) > 1){
        // minA[i] = Xがありうるのか二分探索
        bool ok = true;
        ll cnt = K;
        for(int i = 0; i < N; i++){
            ll target = X - A[i];
            if(target <= 0) continue;
            if(target%(i+1) == 0){
                cnt -= target/(i+1);
            }
            else cnt -= target/(i+1)+1;
            if(cnt < 0){
                ok = false;
                break;
            }
        }
        if(ok){
            // もっと大きくできる。
            l = X;
        }
        else{
            r = X;
        }
        X = (r+l)/2;
    }
    cout << l << endl;
}
