#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;

int main(){
    int N; cin >> N; // N個のボールはすべて白であり、1 ~ Nの番号で区別する
    // つまり、すべてのアイテムが使えるときに限り、すべてのボールを黒にできる。
    // 途中でアイテムが使えなくなるか否かを判定できれば良い
    // グラフを構築？

    // 前からやってもうまくいかない場合は、
    // 後ろから考える
    // 全て黒色のボールのとき、すべて白色にできるか
    /*
        辺が張られている2頂点のうち、少なくとも一方が白のとき、または、
        辺の番号と頂点の番号が一致しているときにのみ、そのアイテムを使える。
    */
    queue<int> que;   // v
    vector<vector<pair<int,int>>> graph(N); // {to,id}
    vector<bool> usedVert(N,false); // 最初はすべての頂点が黒色
    vector<bool> usedItem(N,false); // 最初はすべてのアイテムが未使用
    vector<int> ans;    // アイテムを使う順番
    for(int i = 0; i < N; i++){
        int u,v; cin >> u >> v; u--; v--;
        if(u == i){
            que.push(u);
            usedVert[u] = true;
            usedItem[i] = true;
            ans.push_back(i+1);
        }
        else if(v == i){
            que.push(v);
            usedItem[i] = true;
            usedVert[v] = true;
            ans.push_back(i+1);
        }
        graph[u].push_back({v,i});
        graph[v].push_back({u,i});
    }
    while(!que.empty()){
        auto v = que.front(); que.pop();
        usedVert[v] = true;
        for(auto [nv,id] : graph[v]){
            if(usedItem[id]) continue;
            usedItem[id] = true;
            que.push(id);
            ans.push_back(id+1);
        }
    }
    bool ok = true;
    for(int i = 0; i < N; i++){
        if(usedVert[i] == false){
            // 黒玉が残っていたら
            ok = false;
            break;
        }
    }
    reverse(ans.begin(),ans.end());
    if(ok){
        for(int i = 0; i < N; i++){
            cout << ans[i] << endl;
        }
    }
    else{
        cout << -1 << endl;
    }
}