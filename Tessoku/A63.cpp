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
    vector<int> visited(N,-1);
    visited[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v = que.front(); que.pop();

        for(int nv : graph[v]){
            if(visited[nv] != -1) continue;

            visited[nv] = visited[v] + 1;
            que.push(nv);
        }
    }
    for(int k = 0; k < N; k++){
        cout << visited[k] << endl;
    }
}
