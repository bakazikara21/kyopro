#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    ll one = 0, ten = 0, hand = 0;
    for(int i = 0; i < N; i++){
        ll a; cin >> a;
        a = a%1000;
        if(a == 0) continue;
        a = 1000 - a;

        hand += a / 100;
        a = a % 100;
        ten += a / 10;
        a = a % 10;
        one += a;
    }   
    cout << one << " " << ten << " " << hand << endl; 
}
