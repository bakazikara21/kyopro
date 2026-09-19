#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    string S; cin >> S;
    int N = S.size();

    if(S[N-1] == 'e'){
        S.push_back('r');
    }
    else{
        S.push_back('e');
        S.push_back('r');
    }
    cout << S << endl;
}
