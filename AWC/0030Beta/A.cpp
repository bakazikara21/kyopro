#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    for(int i = 0; i < N; i++){
        int A; cin >> A;
        cout << A/M << " " << A%M << endl;
    }
}
