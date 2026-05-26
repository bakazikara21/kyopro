#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;

int main(){
    int N,Q; cin >> N >> Q;
    string S = "Ambiguous";
    // 
    vector<int> T(Q),X(Q),Y(Q),V(Q);
    for(int i = 0; i < Q; i++){
        cin >> T[i] >> X[i] >> Y[i] >> V[i];

        if(T[i] == 0){
            // このとき、Y[i] = X[i]+1;
            // A[X[i]]+A[Y[i]] = V[i]という情報を得る
        }
        else{
            // A[X[i]] = V[i]ならば
            // UnionFind?
        }
    }
}