#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)inf+7;

int main(){
    int N,P,Q; cin >> N >> P >> Q;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i], A[i]%=P;

    ll ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            for(int k = j+1; k < N; k++){
                for(int l = k+1; l < N; l++){
                    for(int m = l+1; m < N; m++){
                        ll sum = A[i] * A[j]; sum %= P;
                        sum *= A[k]; sum %= P;
                        sum *= A[l]; sum %= P;
                        sum *= A[m]; sum %= P;
                        if(sum == Q) ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}