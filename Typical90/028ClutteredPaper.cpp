#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<vector<ll>> imos(1001,vector<ll>(1001));
    for(int i = 0; i < N; i++){
        int lx,ly,rx,ry;    // 左下の座標と右上の座標
        cin >> lx >> ly >> rx >> ry;

        // 作図しないと厳しいと思う
        // imos[i][j] := (i,j)を左下の頂点とする正方形の領域を表すことにすると
        imos[lx][ly]++;
        imos[rx][ry]++;
        imos[rx][ly]--;
        imos[lx][ry]--;
    }
    for(int i = 0; i < 1000; i++){
        for(int j = 1; j < 1000; j++){
            imos[i][j] += imos[i][j-1];
        }
    }
    for(int j = 0; j < 1000; j++){
        for(int i = 1; i < 1000; i++){
            imos[i][j] += imos[i-1][j];
        }
    }
    vector<ll> ans(N+1);
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            ans[imos[i][j]]++;
        }
    }
    for(int k = 1; k <= N; k++){
        cout << ans[k] << endl;
    }
}