#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class IntervalSet {
public:
    // [l, r] を管理（l <= r）
    set<pair<ll,ll>> st;
    ll covered = 0;  // 覆われている長さの合計

    // 区間 [l, r] を追加
    void add(ll l, ll r) {
        if (l > r) return;

        auto it = st.lower_bound({l, -1});  // 左端が L 以上の最小のiterator

        // 左側と重なる可能性
        if (it != st.begin()) {
            auto pit = prev(it);
            if (pit->second >= l-1) {
                // 一つ手前のiteratorの右端が L-1 以上なら区間を広げられるのでitを更新
                it = pit;
            }
        }

        ll nl = l, nr = r;  // setに追加する候補のL,R

        // 重なる区間をすべて吸収
        // -> L以上R以下は必ず全て覆うので、L以上R以下の隙間は考えなくてよい
        while (it != st.end() && it->first <= r+1) {
            // iterが最後ではなく、かつ、左端が区間内のとき
            nl = min(nl, it->first);
            nr = max(nr, it->second);

            // iteratorを削除するので、該当する区間幅を引き算する
            covered -= (it->second - it->first + 1);
            it = st.erase(it);
        }

        st.insert({nl, nr});    // [l,r]に含まれていた区間を一気に[nl,nr]に統一して広げるイメージ
        covered += (nr - nl + 1);
    }

    // 覆われている要素数
    ll size() const {
        return covered;
    }
};
int main(){
    int N,Q;
    cin >> N >> Q;
    
    IntervalSet inter;
    for(int q = 0; q < Q; q++){
        ll L,R;
        cin >> L >> R;

        inter.add(L,R);
        cout << N-inter.size() << endl;
    }
}
