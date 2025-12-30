#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = (int)1e9;
int main(){
    int N;
    cin >> N;
    vector<vector<int>> graph(N);
    for(int i = 0; i < N-1; i++){
        int u,v;
        cin >> u >> v;
        u--; v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // 頂点1に隣接する頂点がもつ頂点数の合計から最大の頂点数を引いた値を出力すればよい->dfs
    // -> 次数が1になったら頂点1を削除すればよいので、頂点数最大のところだけ引き算する
    // -> 頂点1の次数が1になるまで隣接する点の部分木をすべて削除する
    /*
    if((int)graph[0].size() == 1){
        cout << 1 << endl;
        return 0;
    }
    */

    auto dfs = [&](auto self, int v, int par)->int{

        int cnt = 0;
        for(int nv : graph[v]){
            if(nv == par) continue;

            cnt += self(self,nv,v);
        }
        return cnt+1;
    };
    int ans = 1;
    int maxi = 0;
    for(int v : graph[0]){
        int num = dfs(dfs,v,0);
        ans += num;
        maxi = max(maxi,num);
    }
    ans -= maxi;
    cout << ans << endl;
}
/*
13
1 2
2 3
2 4
2 5
1 6
6 7
7 8
7 9
5 10
5 11
5 12
9 13

*/