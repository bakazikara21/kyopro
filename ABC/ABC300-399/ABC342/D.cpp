#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    map<ll,ll> mp; // 素因数分解に対応するcount
    ll zero = 0;

    vector<ll> dsqu(N);
    for(int i = 0; i < N; i++){
        // A[i]を割り切る最大の平方数を求める
        if(A[i] == 0){
            zero++;
            continue;
        }
        for(ll j = 1; j*j <= A[i]; j++){
            if(A[i]%(j*j) == 0){
                dsqu[i] = j*j;
            }
        }
        mp[A[i]/dsqu[i]]++;
    }

    ll ans = 0;
    for(auto [key,cnt] : mp){
        ans += cnt*(cnt-1)/2;
    }
    ans += (N*zero - zero*(zero+1)/2);
    cout << ans << endl;
}
