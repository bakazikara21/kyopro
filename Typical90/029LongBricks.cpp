#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

// 区間更新 + 区間の最大値を取得する遅延セグメント木
class LazySegmentTree {
    private:
    vector<ll> node;    // 遅延なしのセグメント木の配列
    vector<ll> lazy;    // アクセスしたときのみ更新するための値を保存しておく配列
    int n;

    // 1つのposから遅延を伝播させる関数
    void propagate(int pos, int left, int right) {
        if (lazy[pos] == INF) return; // 遅延がなければ何もしない

        // 自身の node に遅延分を反映
        node[pos] = lazy[pos];

        // 葉ノードでなければ子に伝播
        if (right - left > 1) {
            lazy[pos * 2] = lazy[pos];
            lazy[pos * 2 + 1] = lazy[pos];
        }

        // 伝播し終わったのでINFに戻す
        lazy[pos] = INF;
    }

    public:
    LazySegmentTree(int N):node(2*N,0),lazy(2*N,INF){
        n = N;
    }

    // node[pos]の値を初期化する
    void initialize(vector<ll> A){
        int N = (int)A.size();
        for(int i = 0; i < N; i++){
            node[i+n] = A[i];
        }
        for(int pos = n-1; pos >= 1; pos--){
            node[pos] = max(node[pos * 2],node[pos * 2 + 1]);
        }
    }

    // 区間[l,r)の値をすべてxに更新する
    void update(int l, int r, ll x, int pos = 1, int left = 1, int right = -1){
        /*
            まず、区間[l,r)を高々log(n)個に分割する
            その間に通過するノードは全てlazyを伝播させる
            さらに、通過するノードの更新もO(1)で行う
        */
        if(right < 0) right = n+1;
        // 遅延伝播を逐次行う
        propagate(pos,left,right);

        if(right <= l or r <= left) return; // 範囲外
        if(l <= left and right <= r) {
            lazy[pos] = x;
            propagate(pos,left,right);  // 即、伝播させる
            return;
        }

        // セグメント木の区間和取得のように範囲外になるまで再帰的に処理する
        int mid = (right+left)/2;
        update(l,r,x,pos*2  ,left,mid);
        update(l,r,x,pos*2+1,mid ,right);

        // 子の計算が終わった後、自身の node を再計算して更新する
        node[pos] = max(node[pos * 2],node[pos * 2 + 1]);
    }

    // 区間[l,r)の最大値を返す
    ll getRangeMax(int l, int r, int pos = 1, int left = 1, int right = -1){
        if(right < 0) right = n+1;
        // posでの遅延伝播操作
        propagate(pos,left,right);

        if(right <= l or r <= left) return -INF; // 範囲外
        if(l <= left and right <= r) return node[pos];

        int mid = (right+left)/2;
        ll MaxL = getRangeMax(l,r,pos*2,  left,mid);
        ll MaxR = getRangeMax(l,r,pos*2+1,mid, right);
        return max(MaxL,MaxR);
    }
    ll val(int pos){
        return getRangeMax(pos,pos+1,1,1,n+1);
    }
};
int init(int N){
    int ret = 1;
    while(ret < N) ret *= 2;
    return ret;
}

int main(){
    int W,N; cin >> W >> N;
    // 区間更新 + 区間の最大値がわかればよい.
    int n = init(W);
    LazySegmentTree tree(n);
    for(int i = 0; i < N; i++){
        int L,R; cin >> L >> R;
        ll maxi = tree.getRangeMax(L,R+1); // 区間の最大値を取得
        tree.update(L,R+1,maxi+1);            // 区間更新
        cout << maxi+1 << endl;
    }
}