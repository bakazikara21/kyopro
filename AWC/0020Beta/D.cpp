#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

class IntervalSet {
public:
    set<pair<ll,ll>> st;
    ll length = 0;  // 覆われている長さの合計

    // 区間 [l, r) を追加
    void add(ll l, ll r) {
        if (l >= r) return;

        auto it = st.lower_bound({l, -1});  // 左端が L 以上の最小のiterator

        // 左側と重なる可能性
        if (it != st.begin()) {
            auto pit = prev(it);
            if (pit->second >= l) {
                // 一つ手前のiteratorの右端が L 以上なら区間を広げられるのでitを更新
                it = pit;
            }
        }

        ll nl = l, nr = r;  // setに追加する候補のL,R

        // 重なる区間をすべて吸収
        // -> L以上R以下は必ず全て覆うので、L以上R以下の隙間は考えなくてよい
        while (it != st.end() && it->first <= r) {
            // iterが最後ではなく、かつ、左端が区間内のとき
            nl = min(nl, it->first);
            nr = max(nr, it->second);

            // iteratorを削除するので、該当する区間幅を引き算する
            length -= (it->second - it->first);
            it = st.erase(it);
        }

        st.insert({nl, nr});    // [l,r]に含まれていた区間を一気に[nl,nr]に統一して広げるイメージ
        length += (nr - nl);
    }

    // 覆われている要素数
    ll size() const {
        return length;
    }
};
int main(){
    int N,L; cin >> N >> L;
    IntervalSet Ist;
    for(int i = 0; i < N; i++){
        ll X,R; cin >> X >> R;
        ll left = max(0LL,X-R);
        ll right = min((ll)L,X+R);

        Ist.add(left,right);
    }
    if(Ist.size() == (ll)L) cout << "Yes" << endl;
    else cout << "No" << endl;
}
