#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M;
    string S;
    cin >> N >> M >> S;
    vector<int> C(N);
    vector<deque<char>> color(M);
    for(int i = 0; i < N; i++){
        cin >> C[i];    // i文字目の色
        C[i]--;
        color[C[i]].push_back(S[i]);
    }
    // 各色に対して文字を一回だけ右シフト
    for(int i = 0; i < M; i++){
        char last = color[i].back();
        color[i].pop_back();
        color[i].push_front(last);
    }
    for(int i = 0; i < N; i++){
        cout << color[C[i]].front();
        color[C[i]].pop_front();
    }
    cout << endl;
}
