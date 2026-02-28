#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    int maxi = 0;
    if((N%2) == 0){
        maxi = N/2;
    }
    else maxi = N/2 + 1;
    if(M <= maxi){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}
