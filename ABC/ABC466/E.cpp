#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K; cin >> N >> K;
    vector<int> A(N),B(N),presum(N+1);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
        presum[i+1] = B[i]-A[i] + presum[i];
    }
    // 値が増加する区間を増加幅が大きい区間から10個選ぶだけ
}
