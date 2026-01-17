#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,K;
    ll X;
    cin >> N >> K >> X;
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.rbegin(),A.rend());
    // 多いほうからN-K個飲み干す
    // 次飲めば確実に1個以上飲むことになる
    ll now = 0;
    for(int i = N-K; i < N; i++){
        now += A[i];
        if(now >= X){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
