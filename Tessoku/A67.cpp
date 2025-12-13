#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
最小全域木とは、グラフのすべての点を通る木のなかで、
長さが最小の木のことである。グラフに存在しない辺は使ってはならない。
貪欲に求めることができたはず。閉路ができないように短い順に選べばよい
連結なら追加しない。非連結なら追加してよい
*/
class UnionFind {
    public:
        vector<int> par;   // 点iの親の番号
        vector<int> siz;   // 点iが属するグラフの頂点数

        UnionFind(int N) : par(N), siz(N){
            for(int i = 0; i < N; i++){
                par[i] = i; // 最初は自分自身を親とする

                siz[i] = 1; // 1つの点からなるグラフ
            }
        }

        int root(int v){
            // vが属する連結成分の根を返す関数

            if(par[v] == v) return v;   // 自分自身が根のとき
            return par[v] = root(par[v]); // 自分が根ではないとき根を親にする
        }

        void unite(int u, int v){
            // u,vを連結させる関数

            // u,vの根をそれぞれ求める
            int rootU = root(u);
            int rootV = root(v);
            if(rootU == rootV) return;  // 根が同じなら何もしない

            if(siz[rootU] > siz[rootV]){
                // uの連結成分の頂点数のほうが大きいとき、vをuに繋げる
                par[rootV] = rootU;
            }else if(siz[rootU] < siz[rootV]){
                // 連結成分の頂点数が大きいほうに小さいやつを繋げる
                par[rootU] = rootV;
            }else{
                // 連結成分の頂点数が同じとき
                par[rootU] = rootV;
                siz[rootV] += 1;
            }
        }
};
int main(){
    int N,M;
    cin >> N >> M;
    
    vector<tuple<int,int,int>> edges;
    for(int i = 0; i < M; i++){
        int A,B,C;
        cin >> A >> B >> C;
        A--; B--;   // A < B
        edges.push_back({C,A,B});
    }
    sort(edges.begin(),edges.end());
    UnionFind uf(N);
    ll ans = 0;
    for(int i = 0; i < M; i++){
        auto [C,A,B] = edges[i];
        if(uf.root(A) == uf.root(B)) continue;

        uf.unite(A,B);
        ans += C;
    }
    cout << ans << endl;
}
