#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    強連結成分分解SCCのライブラリ
    有向グラフGにおいて、行き来可能な頂点の極大集合
    深さ優先探索を2回すれば強連結成分分解ができる。

    cycleを1つの頂点として、縮約すると、
    1回目のDFSによって、非巡回有効グラフDAGになる。
    例えば、C -> A -> B
    このとき、帰りがけに付与する数字は N(C) > N(A) > N(B)となる。
    したがって2回目のDFSをするとき、Aに含まれる頂点からスタートして
    C <- A <- B という有効グラフを探索することになる。
    よって、cycleがある集合以外の点に行くことができないようになってる。
    -> 2回DFSすれば強連結成分分解ができる。
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