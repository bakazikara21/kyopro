#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int X; cin >> X; X--;
    string S = "HelloWorld";
    for(int i = 0; i < S.size(); i++){
        if(i == X) continue;
        cout << S[i];
    }
    cout << endl;
}
