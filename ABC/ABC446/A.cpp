#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    string S;
    cin >> S;
    char c = S[0];
    int num = c - 'A';
    S[0] = 'a' + num;
    S = "Of" + S;
    cout << S << endl;
}
