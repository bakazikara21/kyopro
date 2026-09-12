#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N),B(N),ruiseki(N+1);
    ll sum = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        B[i] = A[i];
        sum += A[i];
    }
    sort(B.begin(),B.end());
    for(int i = 0; i < N; i++){
        ruiseki[i+1] = ruiseki[i]+B[i];
    }
    int siz = (int)2e6;
    vector<ll> ans(siz);
    for(int i = 0; i < N; i++){
        // B[i]より大きな要素すべての和を求める
        int t = upper_bound(B.begin(),B.end(),B[i])-B.begin();
        ans[B[i]] = ruiseki[N]-ruiseki[t];
    }
    for(int i = 0; i < N; i++){
        cout << ans[A[i]] << " ";
    }
    cout << endl;
}
