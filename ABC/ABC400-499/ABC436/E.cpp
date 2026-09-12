#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    (1,2,3,...,N)の順列P = (P1, P2, P3, P4, P5, ... , PN)を
    (1,2,3,...,N)と一致させるために必要なswapの回数Kは
    N個の頂点からなるグラフを考えて、i = 1,2,3,...Nに対して
    iとPiを結ぶ辺を追加する。このグラフの連結成分の個数をCとすると
    K = N - Cである。
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

        // vが属する連結成分の根を返す関数
        int root(int v){
            if(par[v] == v) return v;   // 自分自身が根のとき
            return par[v] = root(par[v]); // 自分が根ではないとき根を親にする
        }

        // u,vを連結させる関数
        void connect(int u, int v){
            // u,vの根をそれぞれ求める
            int rootU = root(u);
            int rootV = root(v);
            if(rootU == rootV){
                // 根が同じならなにもしない
                return;
            }; 

            if(siz[rootU] > siz[rootV]){
                // uの連結成分の頂点数のほうが大きいとき、vをuに繋げる
                par[rootV] = rootU;
                siz[rootU] += siz[rootV];
            }else if(siz[rootU] <= siz[rootV]){
                // 連結成分の頂点数が大きいほうに小さいやつを繋げる
                par[rootU] = rootV;
                siz[rootV] += siz[rootU];
            }
        }

        // 頂点vが所属する連結成分の頂点数
        ll numOfVertexs(int v){
            return siz[root(v)];
        }

        // 頂点uと頂点vが同じ連結成分の頂点ならtrue
        bool isConnected(int u, int v){
            return (root(u) == root(v));
        }
};
int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    UnionFind uf(N);
    for(int i = 0; i < N; i++){
        cin >> P[i];    P[i]--;
        /*
            i と　P[i]を繋げてできる連結成分に関して
            同じ連結成分の頂点同士のswapなら最適
            別の連結成分の頂点同士でswapすると連結成分が減少する
        */
        uf.connect(i,P[i]);
    }
    set<int> st;    // 使用した根を管理
    ll ans = 0;
    for(int i = 0; i < N; i++){
        int root = uf.root(i);
        if(st.count(root)) continue;
        st.insert(root);
        ll num = uf.numOfVertexs(root);
        ans += num*(num-1)/2;
    }
    cout << ans << endl;
}