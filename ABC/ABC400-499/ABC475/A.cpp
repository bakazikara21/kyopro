#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    string S; cin >> S;
    for(int i = 0; i < S.size(); i++){
        if(i == S.size()-1) cout << S[i] << endl;
        else cout << S[i] << 'o';
    }
}
