#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(),A.end());

    vector<ll> cnt(N); // Ai~Ai+M-1に含まれるiの数をcount
    for(int i = 0; i < N; i++){
        int u = lower_bound(A.begin(),A.end(),A[i])-A.begin();
        int v = lower_bound(A.begin(),A.end(),A[i]+M)-A.begin();
        cnt[i] = v-u;
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans = max(ans,cnt[i]);
    }
    cout << ans << endl;
}
