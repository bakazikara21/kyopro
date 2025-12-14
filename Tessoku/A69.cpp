#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    int N;
    cin >> N;
    vector<string> C(N);
    for(int i = 0; i < N; i++) cin >> C[i];

    // 生徒iが座りたくない席 C[i][x] = '.'なるx
    MaximumFlow mf(2*N+2);  // start, N人, N席, goal
    for(int i = 1; i <= N; i++){
        mf.addEdge(0,i,1);          // startの点とN人を繋げる
        mf.addEdge(N+i,2*N+1,1);    // N席とgoalの点を繋げる
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(C[i][j] == '#'){
                // i+1の人がN+j+1の席を希望している
                mf.addEdge(i+1,N+j+1,1);
            }
        }
    }
    cout << mf.max_flow(0,2*N+1) << endl;
}
