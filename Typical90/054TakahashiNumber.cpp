#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)inf+7;

/*
    公式解説では、完全グラフの辺の数をN C 2 からNに減らす方法をとっている。
    具体的には、各頂点から新たな頂点へつなぐ辺のみを生成し、
    その辺の重みを0.5として、高橋からの最短経路問題に落とし込んでいる。
*/
int main(){
    int N,M; cin >> N >> M;
    /*
        研究者1（高橋）が含まれるクエリをすべて実行し、共著者の高橋数を確定させる。
        -> 共著者が含まれるクエリをすべて実行し、その人の共著者の高橋数を確定させる。
        -> これをすべてのクエリ、すべての人に対して繰り返す。
    */
    vector<vector<int>> query(N);  // 研究者iが含まれるクエリのindex  
    vector<vector<int>> Query(M);  // クエリiが含む研究者の名簿
    vector<int> K(M);
    vector<int> ans(N,inf);
    ans[0] = 0; // 定義
    for(int i = 0; i < M; i++){
        cin >> K[i];
        for(int k = 0; k < K[i]; k++){
            int R; cin >> R; R--;
            query[R].push_back(i);  // 研究者Rが含まれるクエリのindex
            Query[i].push_back(R);
        }
    }
    queue<int> que;
    que.push(0);    // 0が含まれるクエリからスタート
    vector<bool> usedQ(M,false);
    vector<bool> usedN(N,false);
    while(!que.empty()){
        int v = que.front(); que.pop();
        int num = ans[v];
        for(auto id : query[v]){
            if(usedQ[id]){
                // このクエリを実行済みなら
                continue;
            }
            usedQ[id] = true;
            for(auto human : Query[id]){
                if(ans[human] != inf) continue;

                ans[human] = num+1;
                que.push(human);
            }
        }
    }
    for(int i = 0; i < N; i++){
        if(ans[i] == inf) cout << -1 << endl;
        else cout << ans[i] << endl;
    }
}