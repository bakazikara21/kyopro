#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const int inf = 1e9;
const ll mod = 1e9 + 7;

int bit(ll x){
    int bi = 0;
    while(x > 0){
        bi++;
        x /= 10;
    }
    return bi;
}
int main(){
    int T;
    for(int i = 0; i < T; i++){
        ll C,D;
        cin >> C >> D;

        // 1~Dの間のxについてf(C,C+x)が平方数となる整数xの個数を求めよ
        int bitC = 2*bit(C);
        int bitCD = bit(C+D)+bit(C);

        int mini = sqrt(bitC);
        int maxi = sqrt(bitCD);

        ll imin = pow(10,mini-1);
        ll imax = pow(10,maxi-1);
        for(ll i = imin; i < imax; i++){
            
        }
    }
}