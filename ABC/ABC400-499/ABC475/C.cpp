#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,S; ll L; cin >> N >> S >> L;
    S--;
    vector<ll> sum(N+1);
    for(int i = 1; i < N; i++){
        ll a; cin >> a;
        // i-1 -> iの長さ
        sum[i] += sum[i-1] + a;
    }
    int ans = 1;
    if(S == 0){
        for(int r = 1; r < N; r++){
            bool ok = true;
            ll mnd = sum[r];
            if(mnd > L) ok = false;
            if(ok){
                ans = max(ans,r+1);
            }
        }
    }
    else if(S == N-1){
        for(int l = 0; l < N; l++){
            bool ok = true;
            ll mnd = sum[S] - sum[l];
            if(mnd > L) ok = false;
            if(ok){
                ans = max(ans,N-l);
            }
        }
    }
    else {
        for(int l = 0; l <= S; l++){
            for(int r = S; r < N; r++){
                bool ok = true;
                ll mnd = min((sum[S]-sum[l])*(ll)2+(sum[r]-sum[S]), sum[S]-sum[l]+(ll)2*(sum[r]-sum[S]));
                if(mnd > L) ok = false;
                if(ok){
                    ans = max(ans,r-l+1);
                }
            }
        }
    }
    cout << ans << endl;
}
