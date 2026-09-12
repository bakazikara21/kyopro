#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    int ans = 1;
    map<int,int> mp;    // dp[i] := A[i]までの条件を満たす最長の長さ
    mp[A[0]] = 1;
    for(int i = 1; i < N; i++){
        if(mp.count(A[i]-1)){
            mp[A[i]] = mp[A[i]-1] + 1;
        }
        else mp[A[i]] = 1;
        ans = max(ans,mp[A[i]]);
    }
    cout << ans << endl;
}
