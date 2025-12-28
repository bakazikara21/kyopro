#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = (int)1e9;
// ダブリング
int main(){
    int N,Q;
    cin >> N >> Q;

    vector<int> A(N+1);
    for(int i = 0; i < N; i++){
        cin >> A[i+1];
    }
    vector<int> graph(N+1);
    for(int i = 0; i < N; i++){
        graph[i+1] = A[i+1];    // graph[from]=to
    }
    vector<int> dist(N+1,inf);
    queue<int> que;
    int minCycle;
    for(int i = 1; i <= N; i++){
        if(dist[i] == inf){
            dist[i] = 0;
            que.push(i);
            while(!que.empty()){
                int v = que.front(); que.pop();

                int nv = graph[v];
                if(dist[nv] == inf){
                    dist[nv] = dist[v]+1;
                    que.push(nv);
                }else{
                    minCycle = dist[v]-dist[nv]+1;
                }
            }
        }
        else{
            continue;
        }
    }
    for(int i = 0; i < Q; i++){
        int T,B;
        cin >> T >> B;
    }
}
