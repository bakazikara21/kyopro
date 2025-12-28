#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = (int)1e9;
int main(){
    int N,M;
    cin >> N >> M;

    vector<int> A(M),B(M);
    for(int i = 0; i < M; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    // 二部グラフになればYes->偶数のサイクルはok
    // dfsでサイクルの有無を求める
    vector<vector<int>> graph(N);
    set<pair<int,int>> st;
    for(int i = 0; i < M; i++){
        A[i]--; B[i]--;
        if(st.count({A[i],B[i]})) continue;

        st.insert({A[i],B[i]});
        st.insert({B[i],A[i]});
        graph[A[i]].push_back(B[i]);
        graph[B[i]].push_back(A[i]);
    }
    vector<int> color(N,inf);
    vector<bool> visited(N,false);
    queue<pair<int,int>> que;
    bool ok = true;
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        visited[i] = true;
        que.push({i,0});
        color[i] = 0;
        while(!que.empty()){
            auto [v,col] = que.front(); que.pop();

            for(auto nv : graph[v]){
                if(visited[nv] == true){
                    if(color[nv] == color[v]){
                        ok = false;
                        break;
                    }
                    continue;
                }
                visited[nv] = true;
                color[nv] = 1-color[v];
                que.push({nv,color[nv]});
            }
            if(ok == false) break;
        }
        if(ok == false) break;
    }
    if(ok){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
