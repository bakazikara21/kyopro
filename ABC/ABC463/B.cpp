#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    char X; cin >> X;
    int x = X - 'A';
    bool ok = false;
    for(int i = 0; i < N; i++){
        string S; cin >> S;
        if(S[x] == 'o'){
            ok = true;
        }
    }
    if(ok){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}
