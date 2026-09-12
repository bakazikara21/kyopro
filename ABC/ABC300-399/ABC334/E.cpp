#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
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
ll kurikaesi(ll a, ll b){
    // a^bを求める
    if(b == 1) return a%mod;

    if(b%2 == 0){
        return kurikaesi((a*a) % mod,b/2) % mod;
    }
    else{
        b--;
        return (a%mod)*(kurikaesi((a*a) % mod,b/2) % mod) % mod;
    }
}
int main(){
    int H,W;
    cin >> H >> W;
    
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    // まずP、Qを求める。
    ll P = 0,Q = 0;
    vector<pair<int,int>> Red;
    UnionFind uf(H*W);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '.'){
                Red.push_back({i,j});
            }
            else{
                if(i+1 < H and S[i+1][j] == '#'){
                    uf.unite(i*W+j,(i+1)*W+j);
                }
                if(j+1 < W and S[i][j+1] == '#'){
                    uf.unite(i*W+j,i*W+j+1);
                }
            }
        }
    }   
    Q = (ll)Red.size();

    set<int> st;
    for(int i = 0; i < H*W; i++){
        int x = i/W;
        int y = i%W;
        if(S[x][y] == '.') continue;

        st.insert(uf.root(i));
    }
    vector<ll> E(Q+1);
    E[0] = (ll)st.size();   // 現在の緑の連結成分数
    
    vector<int> di = {0,-1,1,0};
    vector<int> dj = {1,0,0,-1};

    for(int q = 0; q < Q; q++){
        // 赤色に塗られたマスの4近傍をチェックして数え上げる
        auto [i,j] = Red[q];

        vector<pair<int,int>> green;
        set<int> se;    // 連結成分の代表となる根の種類
        for(int k = 0; k < 4; k++){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;

            if(S[ni][nj] == '#'){
                green.push_back({ni,nj});
            }
        }
        if((int)green.size() == 0){
            // 周りに緑マスが0のとき、連結成分数は1増える
            E[q+1] = E[0]+1;
        }
        else if((int)green.size() == 1){
            // 周りに緑マスが1のとき、連結成分数は変わらない
            E[q+1] = E[0];
        }
        else{
            for(auto [ni,nj] : green){
                se.insert(uf.root(ni*W+nj));
            }
            E[q+1] = E[0]-((ll)se.size()-1);
        }
        P += E[q+1];
    }
    ll gcd = __gcd(P,Q);
    P /= gcd;
    Q /= gcd;
    // P,Qは求められたので、Rを求めるだけ
    // R = (P*Q^(mod-2)%mod)
    P %= mod;
    Q = kurikaesi(Q,mod-2)%mod;
    ll R = (P*Q)%mod;
    cout << R << endl;
}
