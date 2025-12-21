#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Trie木を使ってDFSして解く
// 末尾に追加する整数を辺の重みとして実装する
int main(){
    int N;
    cin >> N;
    vector<set<int>> id(N+1); // 頂点iに含まれる添え字

    vector<set<pair<int,int>>> graph(N+1); // 頂点iに{重み,移動先の頂点番号}を記憶させる

    vector<int> vertex(N+1);    // Aiが属する頂点の番号
    map<pair<int,int>,int> mp;  // {xが所属する頂点,重みy}のペアに対して頂点番号を対応させる
    for(int i = 1; i <= N; i++){
        int x,y;
        cin >> x >> y;
        // {x,y}をmap,setで持っておいて記憶しておく
        if(mp.count({vertex[x],y})){
            int ver = mp[{vertex[x],y}];    // 既存の頂点verへ向かうx,y
            id[ver].insert(i);
            vertex[i] = ver;  // Aiが属する頂点の番号はver
        }else{
            mp[{vertex[x],y}] = i;  // {xが所属する頂点,辺の重みy}のペアに対して頂点番号iを割り振る
            vertex[i] = i; // Aiが属する頂点の番号はi
            graph[vertex[x]].insert({y,i});  // xが所属する頂点番号に{重みy,移動先i}を追加する
            id[i].insert(i);
        }
    }
    // 重みは小さい順になっている(setの性質)

    vector<int> P;  // DFSしながら答えをpush_back()していく
    vector<bool> used(N+1,false);
    auto dfs = [&](auto dfs, int v)->void{
        for(auto [w,nv] : graph[v]){
            if(used[nv] == true) continue;

            for(auto num : id[nv]){
                P.push_back(num);
            }
            used[nv] = true;
            dfs(dfs,nv);
            used[nv] = false;
        }   
        used[v] = false;
        return;
    };
    used[0] = true;
    dfs(dfs,0);
    for(int p : P){
        cout << p << " ";
    }
    cout << endl;
}