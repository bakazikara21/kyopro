#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

// 順列全探索の練習問題
int main(){
    int N; cin >> N; // N <= 10;
    vector<vector<int>> A(N,vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }
    int M; cin >> M;
    set<pair<int,int>> st;
    for(int i = 0; i < M; i++){
        int X,Y; cin >> X >> Y; X--; Y--;
        st.insert({X,Y});
        st.insert({Y,X});
    }

    int ans = inf;
    vector<int> pos(N);
    for(int i = 0; i < N; i++) pos[i] = i;
    do{
        bool ok = true;
        int cost = 0;
        cost += A[pos[0]][0];
        for(int i = 1; i < N; i++){
            // i区を走る選手はpos[i]とする
            if(st.count({pos[i-1],pos[i]})){
                ok = false;
                break;
            }
            else cost += A[pos[i]][i];
        }
        if(ok) ans = min(ans,cost);
    }while(next_permutation(pos.begin(),pos.end()));
    if(ans == inf) ans = -1;
    cout << ans << endl;
}