#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
    頂点uと頂点vが連結かどうか
*/
class UnionFind {
    private:
    vector<int> par;    // 頂点iの親
    vector<int> siz;    // 頂点iが属する連結成分の頂点数
    public:
    UnionFind(int N) : par(N),siz(N){
        for(int i = 0; i < N; i++){
            par[i] = i; // 親は自分自身
            siz[i] = 1; // 最初は頂点数1
        }
    }

    // 頂点vの根を返す
    int root(int v){
        if(par[v] == v) return v;
        return par[v] = root(par[v]);
    }

    // 頂点uと頂点vを連結させる
    void connect(int u, int v){
        int rootU = root(u);
        int rootV = root(v);
        if(rootU == rootV){
            // 根が同じなら何もしない
            return;
        }
        if(siz[rootU] > siz[rootV]){
            // Uが属する頂点数 > Vが属する頂点数
            // VをUに連結させる
            par[rootV] = rootU; // Vの根の親をUの根にする
            siz[rootU] += siz[rootV];
        }
        else{
            // Vが属する頂点数 >= Uが属する頂点数
            // UをVに連結させる
            par[rootU] = rootV; // Uの根の親をVの根にする
            siz[rootV] += siz[rootU];
        }
    }

    // 頂点vが属する連結成分の頂点数を返す
    int numOfVertex(int v){
        return siz[root(v)];
    }

    // 頂点uと頂点vが連結ならtrueを返す
    bool isConnected(int u, int v){
        return (root(u)==root(v));
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H,W,Q; cin >> H >> W >> Q;
    vector<bool> red(H*W);
    // N = W*i + j;
    UnionFind uf(H*W);
    vector<int> di = {1,-1,0,0};
    vector<int> dj = {0,0,1,-1};
    for(int q = 0; q < Q; q++){
        int t; cin >> t;
        if(t == 1){
            int i,j; cin >> i >> j; i--; j--;
            int N = W*i + j;
            red[N] = true;
            for(int k = 0; k < 4; k++){
                int ni = i+di[k];
                int nj = j+dj[k];
                int n = W*ni + nj;
                if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
                if(red[n]){
                    uf.connect(N,n);
                } 
            }
        }
        if(t == 2){
            int ai,aj,bi,bj; cin >> ai >> aj >> bi >> bj;
            ai--; aj--; bi--; bj--;
            int a = W*ai + aj;
            int b = W*bi + bj;
            if(red[a] == false or red[b] == false or uf.isConnected(a,b) == false){
                cout << "No" << endl;
            }
            else cout << "Yes" << endl;
        }
    }
}
