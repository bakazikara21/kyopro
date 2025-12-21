#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;

struct TWS {
    ll T;
    ll W;
    ll S;

    // std::setやlower_boundで使うために比較演算子を定義する
    // T (時刻) が早い順に並ぶようにする
    bool operator<(const TWS& other) const {
        return T < other.T;
    }
};

int main() {
    // 入出力の高速化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // 検索と削除を高速に行うため multiset を使用する
    // multisetは要素を自動的にソートして保持する
    multiset<TWS> st;
    for (int i = 0; i < M; i++) {
        ll T, W, S;
        cin >> T >> W >> S;
        st.insert({T, W, S});
    }

    vector<ll> weigh(N, 0);

    for (int i = 0; i < N; i++) {
        ll current_time = 0;
        
        while (true) {
            // current_time 以降で最も早い麺を探す
            // {current_time, -INF, -INF} 以上の最初の要素を検索
            auto it = st.lower_bound({current_time, -INF, -INF});

            // 見つからなければ、この人はこれ以上食べられない
            if (it == st.end()) {
                break;
            }

            // 食べる処理
            weigh[i] += it->W;
            current_time = it->T + it->S; // 次に食べられる時刻を更新

            // 食べた麺を削除する (イテレータを使って削除すると高速かつ安全)
            st.erase(it);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << weigh[i] << "\n";
    }

    return 0;
}