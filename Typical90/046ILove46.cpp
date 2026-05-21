#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;

int main(){
    int N; cin >> N;
    vector<ll> A(N),B(N),C(N),cntA(46),cntB(46),cntC(46);
    for(int i = 0; i < N; i++){ 
      cin >> A[i];
      A[i] %= 46;
      cntA[A[i]]++;
    }
    for(int i = 0; i < N; i++){ 
      cin >> B[i];
      B[i] %= 46;
      cntB[B[i]]++;
    }
    for(int i = 0; i < N; i++){ 
      cin >> C[i];
      C[i] %= 46;
      cntC[C[i]]++;
    }
    ll ans = 0;
    for(ll i = 0; i < 46; i++){
      for(ll j = 0; j < 46; j++){
        ll k = 46 - i - j; k %= 46;
        if(k < 0) k += 46;
        ans += cntA[i] * cntB[j] * cntC[k];
      }
    }
    cout << ans << endl;
}