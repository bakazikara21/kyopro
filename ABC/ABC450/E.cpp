#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    string X,Y; cin >> X >> Y;
    int Q; cin >> Q;
    int N = (int)X.size();
    int M = (int)Y.size();
    vector<ll> cntX(26),cntY(26);
    for(int i = 0; i < N; i++){
        cntX[X[i]-'a']++;
    }
    for(int i = 0; i < M; i++){
        cntY[Y[i]-'a']++;
    }
    for(int q = 0; q < Q; q++){

    }
}
