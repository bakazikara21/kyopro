#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ll N,S,C;
    cin >> N >> S >> C;
    ll cnt = 0;
    for(int i = 0; i < N; i++){
        ll H,P;
        cin >> H >> P;
        if(S >= H){
            S += P-H;
        }
        else cnt++;
    }
    cout << (ll)C * cnt << endl;
}
