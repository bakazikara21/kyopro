#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    // マス(2,2)からポケモンの氷の上のように直進のみ続けた場合、
    // 通過できる氷のマスの個数を求めよ
    // 岩でおおわれている
    // 各マスで、4通りの進行方向のみ
    vector<vector<bool>> used(N,vector<bool>(M,false));
    vector<vector<bool>> reachable(N,vector<bool>(M,false));
    vector<int> di = {1,-1,0,0};
    vector<int> dj = {0,0,1,-1};
   
    queue<pair<int,int>> que;
    que.push({1,1});
    while(!que.empty()){
        auto [i,j] = que.front(); que.pop();
        used[i][j] = true;
        reachable[i][j] = true;
        for(int k = 0; k < 4; k++){
            int ni = i+di[k];
            int nj = j+dj[k];
            while(S[ni][nj] != '#'){
                // 岩ではない限り
                reachable[ni][nj] = true;
                ni += di[k];
                nj += dj[k];
            }
            ni -= di[k];
            nj -= dj[k];
            if(used[ni][nj]) continue;
            used[ni][nj] = true;
            que.push({ni,nj});
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(reachable[i][j]) ans++;
        }
    }
    cout << ans << endl;
}
