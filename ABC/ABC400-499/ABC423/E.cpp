#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N,Q; cin >> N >> Q;
  vector<ll> A(N);
  for(ll &a : A) cin >> a;
  vector<ll> sum(N+1),sumi(N+1),sumi2(N+1);
  for(ll i = 0; i < N; i++){
    sum[i+1] = sum[i] + A[i];
    sumi[i+1] = sumi[i] + i*A[i];
    sumi2[i+1] = sumi2[i] + i*i*A[i];
  }
  for(int q = 0; q < Q; q++){
    ll L,R; cin >> L >> R;
    L--; R--;
    /*
      A[L] + 
      A[L] + A[L+1] +
      A[L] + A[L+1] + A[L+2] + 
      ... + 
      A[L] + A[L+1] + A[L+2] + ... + A[R] +
      A[L+1] + 
      A[L+1] + A[L+2] + 
      A[L+1] + A[L+2] + A[L+3] + 
      ... + 
      A[L+1] + A[L+2] + ... + A[R] +
      ...
      
      A[L] * (R-L+1) + 
      A[L+1] * (R-L+1 - 1) * 2 + 
      A[L+2] * (R-L+1 - 2) * 3 + 
      A[L+3] * (R-L+1 - 3) * 4 +
      ... +
      A[R] * (R-L+1 - (R-L)) * (R-L+1)
    */
    ll ans = 0;
    // for(int i = L; i <= R; i++){
    //   ans += A[i] * (R+1 - i) * (i-L+1);
    //   つまり、
    //   ans += A[i] * ((-L+1)*(R+1) + i*(R+L) - i^2);
    //   ans += A[i] と i*A[i] と i^2*A[i]を事前計算しておく
    // }
    ans += -(sumi2[R+1]-sumi2[L]);
    ans += (R+L)*(sumi[R+1]-sumi[L]);
    ans += (-L+1)*(R+1)*(sum[R+1]-sum[L]);
    cout << ans << endl;
  }
} 