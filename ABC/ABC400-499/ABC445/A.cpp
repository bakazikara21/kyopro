#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    string S;
    cin >> S;
    int N = (int)S.size();
    if(S[0] == S[N-1]){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}
