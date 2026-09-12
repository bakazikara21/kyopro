#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Trie木 : 辺に整数や文字を重み付けしてグラフを構築することで、
整数や文字列を辞書順で管理しやすくする。
*/
class TrieTree{
    public:
        int current_node = 0;
        vector<int> node;                   // node[i]:= Aiが属するノード番号
        vector<set<int>> id;                // id[i]:= i番目のnodeに含まれる添え字の集合
        vector<set<pair<ll,int>>> graph;    // i番目のnodeに{重み,移動先のnode番号}を昇順に記憶させる
        map<pair<int,ll>,int> mp;           // {xが属するnode,重みy}のペアに対してnode番号を対応させる

        TrieTree(int N) : node(N+1),id(N+1),graph(N+1){
            node[0] = 0;    // A[0]のノードを0としてTrie木を構築する
            current_node++; // 次に生成するノード番号をインクリメント
        }

        void query(int i, int x, ll y){
            // A[i]はA[x]の末尾にyを追加した整数
            if(mp.count({node[x],y})){
                // A[x]が属するnodeからの重みyの辺が既に存在するとき
                node[i] = mp[{node[x],y}];  // A[i]が属するノードは既存のもの
                id[node[i]].insert(i);      // A[i]が属するnodeに含まれる添え字を追加(iを追加)
            }
            else{
                // A[x]が属するnodeからの重みyの辺が存在しないとき
                node[i] = current_node;                     // A[i]が属するnodeは最新のノード
                id[node[i]].insert(i);                      // A[i]が属するnodeに含まれる添え字を追加(iを追加)
                mp[{node[x],y}] = current_node;             // A[x]が属するnodeからの重みyの辺を記憶させる
                graph[node[x]].insert({y,current_node});    // A[x]が属するnodeの隣接nodeをsetで管理する

                current_node++; // 次に生成するノード番号をインクリメント
            }
        }

        // 配列Aの整数列を辞書順にしたときの添え字列を出力する
        // 結果を配列で返す設計にすると汎用性が高い
        vector<int> get_sorted_indices() {
            vector<int> res;
            // ラムダ式による再帰
            auto dfs = [&](auto self, int u) -> void {
                // このノードで終わるIDを追加
                for (int idx : id[u]) {
                    res.push_back(idx);
                }
                // 辞書順（重み順）に子ノードへ遷移
                for (auto [w, v] : graph[u]) {
                    self(self, v);
                }
            };
            dfs(dfs, 0);
            return res;
        }
};
// Trie木を使ってDFSして解く
// 末尾に追加する整数を辺の重みとして実装する
int main(){
    int N;
    cin >> N;
    
    TrieTree trie(N);
    for(int i = 1; i <= N; i++){
        int x,y;
        cin >> x >> y;
        // {x,y}をmap,setで持っておいて記憶しておく
        trie.query(i,x,y);
    }
    // 重みは小さい順になっている(setの性質)

    // DFSしながら答えをpush_back()していく
    vector<int> P = trie.get_sorted_indices();
    for(int p : P){
        cout << p << " ";
    }
    cout << endl;
}
