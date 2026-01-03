#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,T;
    cin >> N >> T;
    vector<ll> A(T),B(T),score(N,0);
    map<ll,ll> mp;  // 得点に対するcount
    ll ans = 1;
    mp[0] = N;
    for(int i = 0; i < T; i++){
        cin >> A[i] >> B[i];
        A[i]--;

        mp[score[A[i]]]--;
        if(mp[score[A[i]]] == 0) ans--;

        score[A[i]] += B[i];
        mp[score[A[i]]]++;
        if(mp[score[A[i]]] == 1) ans++;

        cout << ans << endl;
    }
}
