#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        if(A == K){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
