#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ll G,M,D,K,V; cin >> G >> M >> D >> K >> V;
    ll dist = M - G;
    if(G <= D*K){
        ll left = 0;
        if((G*V) % D == 0){
            left = (G*V) / D;
        }
        else left = (G*V) / D + 1;
        if(left <= dist){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    else {
        if((K+G-K*D)*V <= M-G){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}
