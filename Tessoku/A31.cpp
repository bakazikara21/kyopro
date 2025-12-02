#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;

    // 1 <= n <= N のうち3 or 5で割り切れる数の個数
    ll ans = 0;
    ans += N/3;
    ans += N/5;
    ans -= N/15;
    cout << ans << endl;
}
