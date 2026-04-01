#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    区間加算 add(int l, int r, ll x):
    例えば、N=8で区間[1,5]に+3するとき
    区間を[1,4]と[5,5]に最小分割して
    [1,4]に対応するlazyに+3, 
    [5,5]に対応するlazyに+3
    をして終了する。

    クエリ処理の途中で通過する配列全てで
    lazyの値を下の子に伝播させ、値を更新する。
*/
class LazySegmentTree {
    private:
    vector<ll> node;    // 遅延なしのセグメント木の配列
    vector<ll> lazy;    // アクセスしたときのみ更新するための値を保存しておく配列
    int n;

    // 1つのposから遅延を伝播させる関数
    void propagate(int pos, int left, int right) {
        if (lazy[pos] == 0) return; // 遅延がなければ何もしない

        // 自身の node に遅延分を反映（1要素あたりの値 × 区間の長さ）
        node[pos] += lazy[pos] * (right - left);

        // 葉ノードでなければ子に伝播
        if (right - left > 1) {
            lazy[pos * 2] += lazy[pos];
            lazy[pos * 2 + 1] += lazy[pos];
        }

        // 伝播し終わったのでゼロに戻す
        lazy[pos] = 0;
    }

    public:
    LazySegmentTree(int N):node(2*N,0),lazy(2*N,0){
        n = N;
    }

    // node[pos]の値を初期化する
    void initialize(vector<ll> A){
        int N = (int)A.size();
        for(int i = 0; i < N; i++){
            node[i+n] = A[i];
        }
        for(int pos = n-1; pos >= 1; pos--){
            node[pos] = node[pos*2]+node[pos*2+1];
        }
    }

    // 区間[l,r)に+xを加算する
    void add(int l, int r, ll x, int pos = 1, int left = 1, int right = -1){
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
            lazy[pos] += x;
            propagate(pos,left,right);  // 即、伝播させる
            return;
        }

        // セグメント木の区間和取得のように範囲外になるまで再帰的に処理する
        int mid = (right+left)/2;
        add(l,r,x,pos*2  ,left,mid);
        add(l,r,x,pos*2+1,mid ,right);

        // 子の計算が終わった後、自身の node を再計算して更新する
        node[pos] = node[pos * 2] + node[pos * 2 + 1];
    }

    // 区間[l,r)の値の合計を返す
    ll getRangeSum(int l, int r, int pos = 1, int left = 1, int right = -1){
        if(right < 0) right = n+1;
        // posでの遅延伝播操作
        propagate(pos,left,right);

        if(right <= l or r <= left) return 0LL; // 範囲外
        if(l <= left and right <= r) return node[pos];

        int mid = (right+left)/2;
        ll sumL = getRangeSum(l,r,pos*2,  left,mid);
        ll sumR = getRangeSum(l,r,pos*2+1,mid, right);
        return sumL+sumR;
    }

    ll val(int pos){
        return getRangeSum(pos,pos+1,1,1,n+1);
    }
};

int init(int N){
    int ret = 1;
    while(ret < N) ret *= 2;
    return ret;
}
