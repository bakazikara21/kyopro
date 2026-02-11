#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> W(N);
    for (int i = 0; i < N; ++i) cin >> W[i];

    vector<int> C(M);
    for (int i = 0; i < M; ++i) cin >> C[i];

    // 荷物の総重量がトラックの総容量を超えている場合は即座にNo
    // accumulateの初期値を0LLにすることでlong longで計算（オーバーフロー防止）
    long long sumW = accumulate(W.begin(), W.end(), 0LL);
    long long sumC = accumulate(C.begin(), C.end(), 0LL);

    if (sumW > sumC) {
        cout << "No" << endl;
        return;
    }

    // トラックを容量の大きい順にソート
    sort(C.rbegin(), C.rend());

    // 最適化：トラックの数が荷物の数より多い場合、N台に減らす
    if (M > N) {
        M = N;
        C.resize(M);
    }

    // dp_k[mask]: maskの状態を達成するための最小トラックインデックス
    // dp_rem[mask]: その時の最後のトラックの残り容量
    // 初期値として、トラック数はありえない大きな値(M+1)、容量は-1を設定
    vector<int> dp_k(1 << N, M + 1);
    vector<int> dp_rem(1 << N, -1);

    // 初期状態：荷物なし(mask=0)
    // 0番目のトラックを使用開始しており、容量は満タン(C[0])とする
    dp_k[0] = 0;
    dp_rem[0] = C[0];

    // 全ての集合状態（mask）を走査
    for (int mask = 0; mask < (1 << N); mask++) {
        // 現在の状態が到達不可能ならスキップ
        if (dp_k[mask] >= M) continue;

        int current_k = dp_k[mask];
        int current_rem = dp_rem[mask];

        // 次の荷物 i を追加してみる
        for (int i = 0; i < N; ++i) {
            // 既に荷物 i が mask に含まれていればスキップ
            if ((mask >> i) & 1) continue;

            int new_mask = mask | (1 << i);
            int wi = W[i];

            int nk = M + 1; // 次の状態のトラックインデックス
            int nrem = -1;  // 次の状態の残り容量

            // 選択肢1: 現在のトラックに積む
            if (wi <= current_rem) {
                nk = current_k;
                nrem = current_rem - wi;
            }
            // 選択肢2: 新しいトラック(current_k + 1)に積む
            // 次のトラックが存在し、かつ容量が足りる場合
            else if (current_k + 1 < M && wi <= C[current_k + 1]) {
                nk = current_k + 1;
                nrem = C[current_k + 1] - wi;
            }

            // どちらにも積めなかった場合はスキップ
            if (nk > M) continue;

            // DP更新ロジック
            // 1. トラック数が少ない方が良い
            // 2. トラック数が同じなら、残り容量が多い方が良い（＝将来詰め込みやすい）
            if (nk < dp_k[new_mask]) {
                dp_k[new_mask] = nk;
                dp_rem[new_mask] = nrem;
            } else if (nk == dp_k[new_mask]) {
                if (nrem > dp_rem[new_mask]) {
                    dp_rem[new_mask] = nrem;
                }
            }
        }
    }

    // 全ての荷物を含んだ状態 ((1<<N)-1) が有効なトラック数で達成できたか
    if (dp_k[(1 << N) - 1] < M) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    solve();
}
