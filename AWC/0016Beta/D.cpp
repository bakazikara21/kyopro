#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; ll K; int Q; cin >> N >> K >> Q;
    vector<ll> A(N),f(N),prefixF(N+1,0);
    ll sum = 0;
    bool ok = false;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(ok) continue;
        sum += A[i];
        if(sum > K or i+1 == N){
            ok = true;
            f[0] = i+1;
        }
    }
    for(int i = 1; i < N; i++){
        sum -= A[i-1];
        int j = f[i-1] - 1;
        while(j+1 < N and sum <= K){
            j++;
            sum += A[j];
        }
        if(j >= N-1 or sum > K){
            f[i] = j+1;
        }
    }
    for(int i = 0; i < N; i++){
        prefixF[i+1] = prefixF[i] + f[i];
    }
    for(int q = 0; q < Q; q++){
        int L,R; cin >> L >> R;
        cout << prefixF[R]-prefixF[L-1] << endl;
    }
}
