#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;
ll kurikaesi(ll a, ll b){
    if(b == 0) return 1LL;
    if(b == 1) return a%mod;
    if(b%2 == 0){
        return kurikaesi((a*a)%mod, b/2)%mod;
    }
    if(b%2 == 1){
        return ((a%mod)*(kurikaesi((a*a)%mod, b/2)%mod))%mod;
    }
}
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

        void unite(int u, int v){
            // u,vを連結させる関数

            // u,vの根をそれぞれ求める
            int rootU = root(u);
            int rootV = root(v);
            if(rootU == rootV){
                // 根が同じなら辺だけ増加させる
                // すでに辺として繋がっていても増加させてしまう
                edge[rootU]++;
                return;
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
        }

        ll vertexs(int v){
            // 頂点vが所属する連結成分の頂点数
            return siz[root(v)];
        }

        ll edges(int v){
            // 頂点vが所属する連結成分の辺の数
            return edge[root(v)];
        }

        bool isUnited(int u, int v){
            // u,vの根をそれぞれ求める
            int rootU = root(u);
            int rootV = root(v);
            if(rootU == rootV){
                // 根が同じなら
                return true;
            }
            return false;
        }
};
int main(){
    int N,M; cin >> N >> M;
    // 非連結になるまで消していけばグループ分けは最適になるはず
    // 消した中でもともと連結ならばそれを復元する
    vector<tuple<int,int,int>> query(M);
    for(int i = 0; i < M; i++){
        int u,v; cin >> u >> v; u--; v--;
        query[i] = {u,v,i};
    }
    vector<ll> ans;
    UnionFind uf(N);
    UnionFind uf2(N);
    bool ok = false;
    for(int i = M-1; i >= 0; i--){
        auto [u,v,id] = query[i];
        // 全体が連結になるまでクエリを進める
        if(!uf.isUnited(u,v)) uf.unite(u,v);
        if(!ok and uf.vertexs(u) == N){
            // 全体が連結になった
            // これ以下のiのみで非連結にできる
            ok = true;
        }
        else if(!ok){
            // Nにならないならば
            uf2.unite(u,v);
        }
        if(ok){
            if(uf2.isUnited(u,v)){
                // もともと連結ならばいらない
                continue;
            }
            ans.push_back(i+1);
        }
    }
    ll sum = 0;
    for(ll i : ans){
        sum += kurikaesi(2,i)%mod;
        sum %= mod;
    }
    cout << sum << endl;
}
