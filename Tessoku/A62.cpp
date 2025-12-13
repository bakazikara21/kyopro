#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int>> graph(N);
    for(int i = 0; i < M; i++){
        int A,B;
        cin >> A >> B;
        A--; B--;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    vector<bool> visited(N,false);
    visited[0] = true;
    // ラムダ式
    function<void(int)> dfs = [&](int num){
        for(int v : graph[num]){
            if(visited[v] == true) continue;

            visited[v] = true;
            dfs(v);
        }
        return;
    };
    dfs(0);
    bool ok = true;
    for(int i = 0; i < N; i++){
        if(visited[i] == false){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << "The graph is connected." << endl;
    }else{
        cout << "The graph is not connected." << endl;
    }
}
