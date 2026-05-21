#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;

int main(){
    int N,L; cin >> N >> L;
    vector<ll> comb(N+1);
    comb[0] = 1;
    for(int i = 1; i <= N; i++){
        comb[i] = comb[i-1];
        if(i-L >= 0) comb[i] += comb[i-L];
        comb[i] %= mod;
    }
    cout << comb[N] << endl;
}