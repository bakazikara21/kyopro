#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N),cntR(N+1),cntL(N+1);
  
    for(int i = 0; i < N; i++){
        cin >> A[i];
        cntR[A[i]]++; // 現在、右側にある個数
    }

    ll ans = 0, sum = 0;
    for(int j = 1; j < N-1; j++){
        sum -= cntR[A[j-1]]*cntL[A[j-1]];
        cntL[A[j-1]]++;
        cntR[A[j-1]]--;
        sum += cntR[A[j-1]]*cntL[A[j-1]];
        ans += sum;
        ans -= cntR[A[j]]*cntL[A[j]];
    }
    cout << ans << endl;
}