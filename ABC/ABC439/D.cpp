#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // jを固定
    map<ll,ll> mp3,mp7; // countする
    ll ans = 0;
    for(int i = 0; i < N; i++){
        if(A[i]%7 == 0){
            mp7[A[i]]++;
        }
        if(A[i]%3 == 0){
            mp3[A[i]]++;
        }
        if(A[i]%5 == 0){
            ans += mp3[A[i]/5 * 3] * mp7[A[i]/5 * 7];
        }
    }
    map<ll,ll> mp33,mp77; // countする
    for(int i = N-1; i >= 0; i--){
        if(A[i]%7 == 0){
            mp77[A[i]]++;
        }
        if(A[i]%3 == 0){
            mp33[A[i]]++;
        }
        if(A[i]%5 == 0){
            ans += mp33[A[i]/5 * 3] * mp77[A[i]/5 * 7];
        }
    }
    cout << ans << endl;
}
