#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N,D,P;
    cin >> N >> D >> P;

    vector<ll> F(N);    // 通常料金
    for(int i = 0; i < N; i++){
        cin >> F[i];
    }
    sort(F.rbegin(),F.rend());

    ll ans = 0;
    ll miniSum = 0;
    for(int i = 0; i < N; i++){
        miniSum += F[i];
        if((i+1)%D == 0 or i == N-1){
            if(miniSum > P){
                ans += P;
            }else{
                ans += miniSum;
            }
            miniSum = 0;
        }
    }
    cout << ans << endl;
}