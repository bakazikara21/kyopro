#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,Q; cin >> N >> Q;
    vector<ll> V(N);
    for(int i = 0; i < N; i++) cin >> V[i];
    for(int q = 0; q < Q; q++){
        int num; cin >> num;
        if(num == 1){
            int a,b; cin >> a >> b; a--; b--;
            V[b] += V[a];
            V[a] = 0;
        }
        if(num == 2){
            int c; cin >> c; c--;
            cout << V[c] << endl;
        }
    }
}
