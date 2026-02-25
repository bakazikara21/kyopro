#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

struct Edge {
    int to;  // 行き先
    int cap; // 容量
    int rev; // 逆辺のインデックス
};
class MaximumFlow{
    public:
        vector<vector<Edge>> graph;
        vector<bool> visited;   // ->max_flow()で毎回初期化する

        MaximumFlow(int N) : graph(N),visited(N){
            // 頂点数をNに設定する 
            // 逆辺にアクセスしやすいようにidも持っておく
            // graph[i] = {to,capacity,rev_id};
        }

        void addEdge(int u, int v, int c){
            // u->vに最大で水をcリットル流せる
            graph[u].push_back({v,c,(int)graph[v].size()});

            // v->uに水を0リットル返却できる
            graph[v].push_back({u,0,(int)graph[u].size()-1});
        }

        int dfs(int pos, int goal, int Flow){
            // posからgoalまでの経路で最小の容量Flowを返す関数
            visited[pos] = true;
            if(pos == goal) return Flow;

            for(int nv = 0; nv < (int)graph[pos].size(); nv++){
                auto [to,capa,rev_id] = graph[pos][nv];

                if(capa == 0) continue;
                if(visited[to] == true) continue;

                int flow = min(Flow,capa);  // フローは経路の最小値に合わせる(Flowを書き換えないように注意)
                flow = dfs(to,goal,flow);   // フローの最小値を求めて代入する

                if(flow >= 1){
                    graph[pos][nv].cap -= flow;     // 順方向のフローは減少させる
                    graph[to][rev_id].cap += flow;  // 逆辺のフローは増加する 
                    return flow;
                }
            }
            return 0;   // flowのリターンがないとき、流せるflowがない
        }

        int max_flow(int start, int goal){
            // 最大流を返す関数
            int ans = 0;
            while(1){
                for(int i = 0; i < (int)visited.size(); i++){
                    // 訪問履歴を初期化
                    visited[i] = false;
                }
                int flow = dfs(start,goal,(int)1e9);
                if(flow == 0) break;
                ans += flow;
            }
            return ans;
        }
};
int main(){
    int N,M; cin >> N >> M;
    MaximumFlow mf(N+M+2);
    for(int i = 1; i <= N; i++){
        mf.addEdge(0,i,1);
    }
    for(int i = N+1; i <= N+M; i++){
        mf.addEdge(i,N+M+1,1);
    }
    for(int i = 1; i <= N; i++){
        int K; cin >> K;
        for(int k = 0; k < K; k++){
            int C; cin >> C; C += N;
            mf.addEdge(i,C,1);
        }
    }
    cout << mf.max_flow(0,N+M+1) << endl;
}
