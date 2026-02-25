#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ll A,B,C; cin >> A >> B >> C;
    if(A >= B){
        cout << 0 << endl;
        return 0;
    }
    cout << (B-A)*C << endl;
}
