#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 無事、敗北
int main(){
    int N;
    cin >> N;
    vector<ll> A(N+2);
    for(int i = 1; i <= N; i++) cin >> A[i];

    vector<ll> leftPi(N+2);  // iを頂点とする左側のピラミッドのサイズ
    vector<ll> rightPi(N+2);  // iを頂点とする右側のピラミッドのサイズ
    for(int i = 1; i <= N; i++){
        leftPi[i] = min(leftPi[i-1]+1,A[i]);
        rightPi[N-i+1] = min(rightPi[N-i+2]+1,A[N-i+1]);
    }
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        //cout << "i = " << i << " left = " << leftPi[i] << " right = " << rightPi[i] << endl;
        ans = max(ans,min(leftPi[i],rightPi[i]));
    }
    cout << ans << endl;
    //A.insert(A.begin(),0);->初めて見た
}
