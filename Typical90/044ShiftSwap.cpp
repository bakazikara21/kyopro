#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;

int main(){
    int N,Q; cin >> N >> Q;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    
    int pls = 0;
    for(int q = 0; q < Q; q++){
      int T,x,y; cin >> T >> x >> y; x--; y--;
      x = x - pls; y = y - pls;
      x %= N; y %= N;
      if(x < 0) x += N;
      if(y < 0) y += N;
      if(T == 1){
        swap(A[x],A[y]);
      }
      if(T == 2){
        pls++;
      }
      if(T == 3){
        cout << A[x] << endl;
      }
    }
}