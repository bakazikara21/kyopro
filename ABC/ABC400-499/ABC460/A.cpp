#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    int cnt = 0;
    while(M != 0){
        M = (N%M);
        cnt++;
    }
    cout << cnt << endl;
}
