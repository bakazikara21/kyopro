#include <bits/stdc++.h>
using namespace std;

/* T: セグ木のノードに乗せるデータの型 (例: int, long long)
   E: 遅延配列に乗せる作用素の型 (例: int, long long)
*/
template<typename T, typename E>
class LazySegmentTree {
    using F = function<T(T, T)>; // データのマージ (例: min(a, b))
    using G = function<T(T, E)>; // データに作用素を適用 (例: a + b)
    using H = function<E(E, E)>; // 作用素のマージ (例: a + b)

    int n;
    vector<T> data;
    vector<E> lazy;
    
    F f; // query時のマージ関数 (data同士)
    G g; // update時の作用関数 (dataとlazy)
    H h; // lazyの伝搬関数 (lazy同士)
    
    T ti; // dataの単位元 (minならINF, sumなら0)
    E ei; // lazyの単位元 (addなら0, updateなら特殊値)

public:
    LazySegmentTree(int n_, F f, G g, H h, T ti, E ei)
        : f(f), g(g), h(h), ti(ti), ei(ei) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2 * n, ti);
        lazy.assign(2 * n, ei);
    }

    // 配列で初期化する場合
    void build(const vector<T>& v) {
        for (int i = 0; i < v.size(); i++) data[i + n] = v[i];
        for (int i = n - 1; i > 0; i--) data[i] = f(data[2 * i], data[2 * i + 1]);
    }

    // 遅延評価を行う関数（一番重要）
    void eval(int k) {
        if (lazy[k] == ei) return; // 遅延情報がなければ何もしない

        if (k < n) { // 葉でなければ子に伝搬
            lazy[2 * k] = h(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
        }
        // 自分自身を更新
        data[k] = g(data[k], lazy[k]);
        lazy[k] = ei; // 伝搬完了したので初期化
    }

    // 区間更新 [a, b) に x を作用させる
    void update(int a, int b, E x) {
        update(a, b, x, 1, 0, n);
    }

    void update(int a, int b, E x, int k, int l, int r) {
        eval(k); // 訪問したらまず評価
        if (a <= l && r <= b) { // 完全に区間に含まれる場合
            lazy[k] = h(lazy[k], x);
            eval(k); // 遅延をセットしたらすぐに評価してdataを更新しておく
        } else if (a < r && l < b) { // 一部重なる場合
            update(a, b, x, 2 * k, l, (l + r) / 2);
            update(a, b, x, 2 * k + 1, (l + r) / 2, r);
            data[k] = f(data[2 * k], data[2 * k + 1]);
        }
    }

    // 区間取得 [a, b)
    T query(int a, int b) {
        return query(a, b, 1, 0, n);
    }

    T query(int a, int b, int k, int l, int r) {
        eval(k); // 訪問したらまず評価
        if (r <= a || b <= l) return ti;
        if (a <= l && r <= b) return data[k];
        T vl = query(a, b, 2 * k, l, (l + r) / 2);
        T vr = query(a, b, 2 * k + 1, (l + r) / 2, r);
        return f(vl, vr);
    }
    
    // デバッグ用：現在の配列の状態を表示
    void debug() {
        for(int i = 0; i < n; i++) {
            // 葉の遅延を解消してから表示する工夫が必要だが、簡易的にはqueryを呼ぶ
            cout << query(i, i+1) << " ";
        }
        cout << endl;
    }
};
// 以下は使い方
int main() {
    int N = 8;
    
    // 各関数の定義
    // f: 子のデータ同士をどうマージするか -> 最小値なので min
    auto f = [](int a, int b) { return min(a, b); };
    
    // g: データ(a)に作用素(b)をどう適用するか -> 加算なので a + b
    auto g = [](int a, int b) { return a + b; };
    
    // h: 既に溜まっている遅延(a)に新しい遅延(b)をどう合成するか -> 加算なので a + b
    auto h = [](int a, int b) { return a + b; };

    // 単位元
    int INF = 1e9 + 7;
    int ti = INF; // minの単位元
    int ei = 0;   // addの単位元

    // インスタンス生成
    LazySegmentTree<int, int> seg(N, f, g, h, ti, ei);

    // 初期データを入れる（最初は全部0とする場合）
    vector<int> initial(N, 0);
    seg.build(initial);

    // クエリ処理の例
    seg.update(0, 3, 10); // [0, 3) に +10 -> {10, 10, 10, 0, 0, ...}
    seg.update(2, 5, 5);  // [2, 5) に +5  -> {10, 10, 15, 5, 5, 0, ...}

    cout << seg.query(0, 8) << endl; // 全体の最小値 -> 0
    cout << seg.query(0, 3) << endl; // [0, 3)の最小値 -> 10
    cout << seg.query(2, 4) << endl; // [2, 4)の最小値 -> 5 ({15, 5})
}