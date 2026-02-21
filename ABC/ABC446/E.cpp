#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

/*
    頂点倍加みたいなことをすれば解けそう
*/
int main(){
    int M,A,B;
    cin >> M >> A >> B;
    // ans <= (M-1)*(M-1)
    vector<vector<int>> rest(M,vector<int>(M));
    int ans = 0;
    for(int x = 1; x < M; x++){
        for(int y = 1; y < M; y++){
            rest[x][y] = (A*x + B*y)%M; // (x,y)に対するあまり
            //cout << "x = " << x << " y = " << y << " amari = " << rest[x][y] << endl;
        }
    }
    
    cout << ans << endl;
}
