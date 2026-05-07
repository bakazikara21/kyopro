#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ll a,b,c; cin >> a >> b >> c;
    ll d = 1;
    for(ll bb = 0; bb < b; bb++){
        d *= c;
    }
    if(a < d){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}