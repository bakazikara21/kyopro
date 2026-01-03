#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N,M,K;
    cin >> N >> M >> K;

    ll gcd = __gcd(N,M);
    ll L = N/gcd * M;   // 最大公約数

    ll left = 0;
    ll right = K*(N+M);
    ll mid = (right+left)/2;
    while((right-left) > 1){
        // answer =　midだと決め打ち->このときの個数を求める
        ll num = mid/N + mid/M - 2 * (mid/L);
        
        if(num >= K){
            // midが大きすぎた
            right = mid;
        }
        else left = mid;

        mid = (right+left)/2;
    }
    cout << right << endl;
    /*
    cout << "Left = " << left << " num = ";
    cout << left/N + left/M - 2*(left/L) << endl;
    */
}
