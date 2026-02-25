#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        int N,M,K; cin >> N >> M >> K;
        string S; cin >> S;
        vector<vector<int>> graph(N);
        vector<vector<string>> ans(N,vector<string>(2*K+1));
        for(int i = 0; i < M; i++){
            int u,v; cin >> u >> v; u--; v--;
            graph[u].push_back(v);
        }
        for(int i = 0; i < N; i++){
            // 2*K回目に頂点iにいるとき
            if(S[i] == 'A'){
                // 頂点iに'A'が書かれていたら
                ans[i][2*K] = "Alice";
            }
            else ans[i][2*K] = "Bob";
        }
        for(int k = 2*K-1; k >= 0; k--){
            for(int i = 0; i < N; i++){
                if(k%2 == 0){
                    // 偶数回目はAliceが動かせる
                    bool ok = false;
                    for(int nv : graph[i]){
                        if(ans[nv][k+1] == "Alice") ok = true;
                    }
                    if(ok){
                        ans[i][k] = "Alice";
                    }
                    else ans[i][k] = "Bob";
                }
                if(k%2 == 1){
                    // 奇数回目はBobが動かせる
                    bool ok = false;
                    for(int nv : graph[i]){
                        if(ans[nv][k+1] == "Bob") ok = true;
                    }
                    if(ok){
                        ans[i][k] = "Bob";
                    }
                    else ans[i][k] = "Alice";
                }
            }
        }
        // for(int k = 0; k <= 2*K; k++){
        //     for(int i = 0; i < N; i++){
        //         cout << ans[i][k] << " ";
        //     }
        //     cout << endl;
        // }
        cout << ans[0][0] << endl;
    }
}
