#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

// 強連結成分分解の典型問題
/*
    強連結成分(SCC)とは:
    有効グラフにおいて、どの頂点同士も互いに行き来できる極大集合
    SCCに分解して、kC2 をすべてのSCCで足せば終了
*/
class SCC {
    public:
    vector<vector<int>> graph;     // graph[i]:頂点iから行ける頂点の集合
    vector<vector<int>> revgraph;  // revgraph[i]:頂点iに入ってくる頂点の集合
    stack<int> sta;                // 1回目のDFSで使う。辿った頂点を順にstackに入れて、最後に入れた頂点から取り出せばよい。
    vector<bool> used;

    int n;                      // グラフGの頂点数
    SCC(int N):graph(N),revgraph(N),used(N,false){
        n = N;
    }

    void addEdge(int u, int v){
        // 頂点uから頂点vへの辺を追加
        graph[u].push_back(v);
        revgraph[v].push_back(u);
    }

    vector<vector<int>> scc(){
        // 強連結成分分解したあとの集合を返す関数
        vector<vector<int>> ret;

        // cycleの極大集合をretにpushしていけばよい。
        // 深さ優先探索を2回すれば強連結成分分解ができることを利用する
        for(int v = 0; v < n; v++){
            // 頂点vからstartして1回目のDFSを行う。
            if(used[v]) continue;
            dfs1(v);
        }
        for(int i = 0; i < n; i++) used[i] = false; // 初期化してもう一度利用する

        while(!sta.empty()){
            int v = sta.top(); sta.pop();
            // 2回目のdfs: 今度は逆辺グラフを使ってdfsをする
            if(used[v]) continue;
            vector<int> add;
            dfs2(v,add);
            ret.push_back(add);
        }
        return ret;
    }

    private:
    void dfs1(int v){
        used[v] = true;
        for(auto nv : graph[v]){
            if(used[nv]) continue;
            dfs1(nv);
        }
        sta.push(v);
    }
    void dfs2(int v, vector<int>& add){
        used[v] = true;
        add.push_back(v);
        for(auto nv : revgraph[v]){
            if(used[nv]) continue;
            dfs2(nv,add);
        }
    }
};
int main(){
    int N,M; cin >> N >> M;
    SCC sccgraph(N);
    for(int i = 0; i < M; i++){
        int A,B; cin >> A >> B; A--; B--;
        sccgraph.addEdge(A,B);
    }
    vector<vector<int>> sets = sccgraph.scc();
    // cycleと、そのcycleの頂点数を求めればよい。
    // 1つのcycleにk頂点あるならば ans += kC2;
    ll ans = 0;
    for(auto st : sets){
        ll k = (ll)st.size();
        ans += k*(k-1)/2;
    }
    cout << ans << endl;
}