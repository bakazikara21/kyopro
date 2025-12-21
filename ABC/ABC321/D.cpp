#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;
    
    ll P;
    cin >> P;
    vector<ll> A(N),B(M);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < M; i++){
        cin >> B[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    vector<ll> ruisekiB(M+1);
    for(int i = 0; i < M; i++){
        ruisekiB[i+1] = ruisekiB[i] + B[i];
    }
    ll sum = 0;
    for(int i = 0; i < N; i++){
        // Ai+Bを考える
        int j = upper_bound(B.begin(),B.end(),P-A[i])-B.begin();
        
        sum += j*A[i] + ruisekiB[j] + P*(M-j);
    }
    cout << sum << endl;
}
