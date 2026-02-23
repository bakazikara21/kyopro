#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n,m;  
    cin >> n >> m;
    vector<ll> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    sort(x.begin(), x.end());
    vector<ll> diff(n-1);
    for(int i = 0; i < n-1; i++){
        diff[i] = x[i+1]-x[i];
        //cout << diff[i] << endl;
    }
    sort(diff.begin(),diff.end());
    ll ans = 0;
    for(int i = 0; i < n-1-(m-1); i++){
        ans += diff[i];
        //cout << diff[i] << endl;
    }
    cout << ans << endl;
}