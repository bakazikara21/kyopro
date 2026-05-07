#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ll A,B,C; cin >> A >> B >> C;
    ll gcd = __gcd(A,__gcd(B,C));
    cout << (A/gcd) + (B/gcd) + (C/gcd) - 3 << endl;
}