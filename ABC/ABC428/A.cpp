#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const int inf = 1e9;
const ll mod = 1e9 + 7;

int main(){
    int S,A,B,X;
    cin >> S >> A >> B >> X;

    int r = X % (A+B);
    r = min(r,A);
    int ans = S*r;
    ans += X / (A+B) * S * A;
    cout << ans << endl;
}