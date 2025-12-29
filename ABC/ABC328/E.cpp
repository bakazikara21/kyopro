#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

        bool unite(int u, int v){
            // u,vを連結させる関数

            // u,vの根をそれぞれ求める
            int rootU = root(u);
            int rootV = root(v);
            if(rootU == rootV) return false;  // 根が同じなら何もしない

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
            return true;
        }
};
int main(){
    int N,M;
    cin >> N >> M;
    ll K;
    cin >> K;

    // mCn-1個の辺を順列全探索
    vector<int> pos(M);
    vector<tuple<int,int,ll>> edges(M);
    for(int i = 0; i < N-1; i++){
        pos[i] = 1; // 1が立っているbitのみを辺として使う->mCn-1
    }
    sort(pos.begin(),pos.end());    // sortしないと全探索にならない

    for(int i = 0; i < M; i++){
        int u,v;
        cin >> u >> v;
        u--; v--;
        ll w;
        cin >> w;

        edges[i] = {u,v,w};
    }
    ll ans = K+1;
    do{
        UnionFind uf(N);
        bool ok = true;
        ll cost = 0;
        for(int i = 0; i < M; i++){
            // pos[i]==1のとき辺iを使用する
            if(pos[i] == 1){
                // 辺iを使用する
                auto [u,v,w] = edges[i];
                cost += (w%K);
                cost %= K;
                ok = uf.unite(u,v);
            }
            if(ok == false){
                break;
            }
        }
        
        if(ok){
            ans = min(ans,cost);
        }
    }while(next_permutation(pos.begin(),pos.end()));

    cout << ans << endl;
}
