#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class UnionFind {
    public:
        vector<int> par;   // 点iの親の番号
        vector<ll> siz;   // 点iが属するグラフの頂点数
        vector<ll> edge;   // 点iが属するグラフの辺の数

        UnionFind(int N) : par(N), siz(N), edge(N){
            for(int i = 0; i < N; i++){
                par[i] = i; // 最初は自分自身を親とする

                siz[i] = 1; // 1つの点からなるグラフ

                edge[i] = 0;    // 最初は辺は0個
            }
        }

        int root(int v){
            // vが属する連結成分の根を返す関数

            if(par[v] == v) return v;   // 自分自身が根のとき
            return par[v] = root(par[v]); // 自分が根ではないとき根を親にする
        }

        bool unite(int u, int v){
            // u,vを連結させる関数

            // u,vの根をそれぞれ求める
            int rootU = root(u);
            int rootV = root(v);
            if(rootU == rootV){
                // 根が同じなら辺だけ増加させる
                // すでに辺として繋がっていても増加させてしまう
                edge[rootU]++;
                return false;
            }; 

            if(siz[rootU] > siz[rootV]){
                // uの連結成分の頂点数のほうが大きいとき、vをuに繋げる
                par[rootV] = rootU;
                siz[rootU] += siz[rootV];
                edge[rootU] += edge[rootV] + 1;
            }else if(siz[rootU] < siz[rootV]){
                // 連結成分の頂点数が大きいほうに小さいやつを繋げる
                par[rootU] = rootV;
                siz[rootV] += siz[rootU];
                edge[rootV] += edge[rootU] + 1;
            }else{
                // 連結成分の頂点数が同じとき
                par[rootU] = rootV;
                siz[rootV] += siz[rootU];
                edge[rootV] += edge[rootU] + 1;
            }
            return true;
        }

        ll vertexs(int v){
            // 頂点vが所属する連結成分の頂点数
            return siz[root(v)];
        }

        ll edges(int v){
            // 頂点vが所属する連結成分の辺の数
            return edge[root(v)];
        }
};
int main(){
    int N,M;
    cin >> N >> M;

    vector<int> K(M);
    vector<pair<ll,int>> C(M);
    vector<vector<int>> A(M);
    for(int i = 0; i < M; i++){
        cin >> K[i] >> C[i].first;
        C[i].second = i;
        for(int k = 0; k < K[i]; k++){
            int a;
            cin >> a;
            a--;
            A[i].push_back(a);
        }
    }
    sort(C.begin(),C.end());
    UnionFind uf(N);
    // {cost,u,v}:= uとvを繋ぐ辺であり、コストcostがかかる辺
    //priority_queue<tuple<ll,int,int>> pq;
    ll ans = 0;
    for(int i = 0; i < M; i++){
        auto [cost,id] = C[i];
        for(int k = 1; k < K[id]; k++){
            // A[id][0]とA[id][k]を辺でつなげば十分
            bool ok = uf.unite(A[id][0],A[id][k]);
            if(ok){
                // 連結でない2点ならば
                ans += cost;
            }
        }
    }
    bool ok = true;
    /*
    */
   for(int i = 0; i < N-1; i++){
       if(uf.root(i) != uf.root(i+1)){
           ok = false;
           break;
       }
   }
    if(ok){
        cout << ans << endl;
    }
    else cout << -1 << endl;
}
