#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];

    vector<ll> ruisekiA(N+1),ruisekiB(N+1),ruisekiC(N+1);
    vector<ll> ruiAB(N+1),ruiBC(N+1),ruiABmax(N+1);
    for(int i = 0; i < N; i++){
        ruisekiA[i+1] = ruisekiA[i]+A[i];
        ruisekiB[i+1] = ruisekiB[i]+B[i];
        ruisekiC[i+1] = ruisekiC[i]+C[i];

        ruiAB[i+1] = ruisekiA[i+1]-ruisekiB[i+1];
        ruiBC[i+1] = ruisekiB[i+1]-ruisekiC[i+1];
    }

    ll maxiAB = ruiAB[1];
    for(int y = 2; y < N; y++){
        // 1~y-1までのruisekiABの最大値
        maxiAB = max(maxiAB,ruiAB[y-1]);
        ruiABmax[y] = maxiAB;
    }
    ll ans = 0;
    for(int y = 2; y < N; y++){
        // yを固定して、区間1~y-1の最大ruiAB[x]を高速に求めればよい
        ll maxi = ruiBC[y];
        maxi += ruisekiC[N]+ruiABmax[y];
        ans = max(ans,maxi);
    }
    cout << ans << endl;
}
