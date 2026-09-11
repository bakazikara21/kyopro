#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

// 帰りがけDFSなら一発
int main(){
    int N; cin >> N;
    vector<vector<int>> graph(N+1);
    vector<int> in(N+1);
    for(int i = 0; i < N; i++){
        int C; cin >> C;
        for(int j = 0; j < C; j++){
            int P; cin >> P;
            graph[i+1].push_back(P);
            in[P]++;
        }
    }
    // 頂点1から辿れない辺は無視するように計算する
    vector<bool> unreachable(N+1,true);
    queue<int> que;
    que.push(1);
    unreachable[1] = false;
    while(!que.empty()){
        int v = que.front(); que.pop();

        for(int nv : graph[v]){
            if(unreachable[nv] == false) continue;
            que.push(nv);
            unreachable[nv] = false;
        }
    }
    for(int i = 1; i <= N; i++){
        if(unreachable[i]){
            for(int nv : graph[i]){
                in[nv]--;
            }
        }
    }

    // 頂点1を含む連結グラフのトポロジカルソートを後ろから並べたのが答え
    vector<int> ans;
    que.push(1);
    while(!que.empty()){
        int v = que.front(); que.pop();

        for(int nv : graph[v]){
            in[nv]--;
            if(in[nv] == 0){
                que.push(nv);
                ans.push_back(nv);
            }
        }
    }
    reverse(ans.begin(),ans.end());
    for(int v : ans) cout << v << " ";
    cout << endl;
}
