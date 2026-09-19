#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    string S,T; cin >> S >> T;
    bool ok = true;
    for(int i = 0; i < N; i++){
        if(T[i] == '*') continue;
        if(T[i] != S[i]) ok = false;
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
