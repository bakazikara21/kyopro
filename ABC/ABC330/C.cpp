#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll an(ll x, ll y, ll D){
    return abs(x*x+y*y-D);
}
int main(){
    ll D;
    cin >> D;

    // abs(x^2+y^2-D)の最小値を求めよ
    ll mini = 1e15;
    ll x = 0;
    while(x*x < D){ // 1e6
        x++;
    }
    // xはぎりぎりDを超えている 
    for(ll y = 0; y*y <= D; y++){   // 1e6
        while(x*x+y*y > D){ // +1e6
            x--;
        }
        x++;
        mini = min(mini,an(x,y,D));
        mini = min(mini,an(x-1,y,D));
    }
    cout << mini << endl;
}