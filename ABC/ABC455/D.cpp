#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

// 途中経過は関係ない   ->  最後に一気に計算すればよい
// 所属する山は最も下にあるカードの値と等しい
// グラフを繋いだり、外したりして最後にどこに所属するかを考えればよい(dfs)
int main(){
    int N,Q; cin >> N >> Q;
    vector<pair<int,int>> graph(N);  // (上につながっている点、下につながっている点)
    for(int i = 0; i < N; i++){
        // 点iに対して
        graph[i] = {-1,-1}; // 最初は、どの点も孤独
    }
    for(int q = 0; q < Q; q++){
        int C,P; cin >> C >> P; C--; P--;
        // 点Cの下に点Pを繋げる操作をする
        int Cd = graph[C].second;
        if(Cd != -1){
            // Cの下に点が存在するなら
            graph[Cd].first = -1;   // あなたが頂点になります。
        }
        graph[C].second = P;    // 点Cの下に点P
        graph[P].first = C;     // 点Pの上に点C
    }
    vector<int> ans(N);
    vector<int> top;    // 底の点から一気に数を計算する
    for(int i = 0; i < N; i++){
        if(graph[i].second == -1){
            //cout << "一番下：" << i << endl;
            top.push_back(i);
        }
    }
    for(auto v : top){
        int target = v;
        int cnt = 1;
        while(graph[v].first != -1){
            // 上の点がいるかぎり
            cnt++;
            v = graph[v].first;
        }
        ans[target] = cnt;
    }
    for(int v = 0; v < N; v++){
        cout << ans[v] << " ";
    }
    cout << endl;
}
