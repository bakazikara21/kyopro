#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    vector<int> row(N,-1),col(N,-1);
    for(int i = 0; i < M; i++){
        int R,C; cin >> R >> C;
        R--; C--;
        if(col[C] >= 0){
            row[col[C]] = -1;
        }
        if(row[R] >= 0){
            col[row[R]] = -1;
        }
        row[R] = C;
        col[C] = R;
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(row[i] >= 0) ans++;
    }
    cout << ans << endl;
}
