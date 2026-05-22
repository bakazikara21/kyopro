#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;

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
/*
    長さNの任意のビット列Tを"000000000000000..."に一致させるのに
    少なくとも必要なアイテムの合計価格の最大値を求める。
*/
int main(){
    int N,M; cin >> N >> M;
    
    // {cost, int u, int v}
    priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>>> pq;
    for(int i = 0; i < M; i++){
        ll C; int L,R;
        cin >> C >> L >> R;
        pq.push({C,L-1,R});
    }
    /*
        隣接XORの配列 D を考える
        D[0] = S[0], D[N] = S[N-1], もしくはS[-1] = 0, S[N] = 0,
        D[i] = S[i-1] xor S[i];
        そうすると S[L]~S[R]がビット反転すると
        D[L]とD[R+1]の値のみビット反転する

        実は、任意のビット列 T を作れる
        <=> 任意の差分列 D を作れる (Dのpop_countは必ず偶数であることは容易にわかる)

        S = 0 10011 0  -> Sは2^5 = 32通りのビット列をもつ
        ->
        D = 110101     -> 6ビットのビット列であり、偶数個のビットが必ず立つから2^6/2 = 32通り

        S = 0 00000 0
        ->
        D = 000000

        S = 0 11111 0
        ->
        D = 100001

        最初、S = 00000... なので D = 00000...である。
        コストCを払うと、D[L]とD[R+1]のビットを独立に反転できる。
        任意のビット列Dを作れるようにするための最小コストは？

        頂点を 0,1,2,...,N としてそれぞれをD[0],D[1],...,D[N]に対応させる。
        D[L],D[R+1]が同時に反転するとき、頂点 L,R+1 を相互に結んでグラフを作ることにする。このとき
        頂点u,vのパスが存在するならば、D[u],D[v]を独立にビット反転できることが言える。(半分自明)
        つまり、グラフが連結であれば、任意の差分列 D を作れることがわかる。同値な気がする
    */
    int n = N+1;
    UnionFind uf(n);

    ll ans = 0;
    while(!pq.empty()){
        auto [cost, u, v] = pq.top(); pq.pop();
        if(uf.isConnected(u,v)) continue;
        ans += cost;
        uf.connect(u,v);
    }
    bool ok = (uf.numOfVertexs(0) == n);
    if(!ok){
        cout << -1 << endl;
    }
    else{
        // 連結グラフならば
        cout << ans << endl;
    }
}