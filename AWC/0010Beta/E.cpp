#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

/*
    (1,2,3,...,N)の順列P = (P1, P2, P3, P4, P5, ... , PN)を
    (1,2,3,...,N)と一致させるために必要なswapの回数Kは
    N個の頂点からなるグラフを考えて、i = 1,2,3,...Nに対して
    iとPiを結ぶ辺を追加する。このグラフの連結成分の個数をCとすると
    K = N - Cである。
*/
int main(){
    int N,K;
    cin >> N >> K;
    vector<vector<ll>> C(N,vector<ll>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> C[i][j];
        }
    }
   
    vector<int> pos(N);
    for(int i = 0; i < N; i++){
        pos[i] = i;
    }
    ll ans = 0;
    do{
        vector<int> graph(N);
        for(int i = 0; i < N; i++){
            // iとPiを結ぶ辺を追加する。
            graph[i] = pos[i];
        }
        vector<bool> visited(N,false);
        auto dfs = [&](auto self, int v)->void{
            if(visited[v] == true) return;
            visited[v] = true;
            self(self,graph[v]);
        };
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if(visited[i] == false){
                cnt++;
                dfs(dfs,i);
            }
        }
        int k = N - cnt;
        if(k > K) continue;

        // スワップ回数がK回以下ならば
        ll sum = 0;
        for(int i = 0; i < N-1; i++){
            sum += C[pos[i]][pos[i+1]];
        }
        sum += C[pos[N-1]][pos[0]];
        //cout << "sum = " << sum << endl;
        ans = max(ans,sum);
    }while(next_permutation(pos.begin(),pos.end()));
    cout << ans << endl;
}