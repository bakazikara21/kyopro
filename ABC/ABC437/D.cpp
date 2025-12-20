#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
int main(){
    int N,M;
    cin >> N >> M;
    // 
    vector<ll> A(N),B(M),ruisekiB(M+1);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < M; i++){
        cin >> B[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i = 0; i < M; i++){
        ruisekiB[i+1] = ruisekiB[i]+B[i];
    }
    ll sum = 0;
    for(int i = 0; i < N; i++){
        int t = lower_bound(B.begin(),B.end(),A[i])-B.begin();

        ll subt = (M-t)*A[i];

        sum += ((t)*A[i]) % mod; sum %= mod;
        sum += (ruisekiB[M]-subt) % mod; sum %= mod;
       
        sum -= (2*ruisekiB[t]) % mod; sum %= mod;
        //cout << "t = " << t << " sum = " << sum << " ruisekiB[t] = " << ruisekiB[t] << endl;
    }
    if(sum < 0) sum += mod;
    cout << sum << endl;
}