#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;

/*
    期待値の線形性を利用して解く
    数列全体の転倒数の期待値は、
    (i,j)の転倒数の期待値の和（1 <= i < N, i+1 <= j <= N）
*/
int main(){
    int N; cin >> N;
    vector<ll> L(N),R(N);
    long double ans = 0;    // まず、分子の計算をする。その後、割り算をする
    for(int i = 0; i < N; i++){
        cin >> L[i] >> R[i];
        ans /= (R[i]-L[i]+1);

        if(i >= 1){
            // L[i]~R[i]のなかでL[i-1]~R[i-1]より小さい整数の総数
            if(L[i] >= R[i-1]) continue;    // 転倒数が存在しないとき
            if(L[i-1]-L[i] > 0){
                ans += (R[i-1]-L[i-1]-1)*(L[i-1]-L[i]);
            }
            ll x = max(L[i],L[i-1]-1);
            if(R[i] < x) continue;
            ans += (R[i]-x)*R[i-1];
            ans -= R[i]*(R[i]+1)/2;
            ans += x*(x-1)/2;
        }
    }
    for(int i = 0; i < N; i++){
        ans /= (R[i]-L[i]+1);
    }
    cout << fixed << setprecision(15);
    cout << ans << endl;
}