#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,X; cin >> N >> X;
    for(int i = 0; i < N; i++){
        int A; cin >> A;
        if(A < X){
            X = A;
            cout << 1 << endl;
        }
        else cout << 0 << endl;
    }
}
