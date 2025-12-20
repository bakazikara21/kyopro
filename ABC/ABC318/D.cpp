#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;

    int cnt = 0;
    if(N%2 != 0) cnt++;
    vector<vector<ll>> D(N+cnt,vector<ll>(N+cnt));
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            ll d;
            cin >> d;
            D[i][j] = d;
        }
    }
    // 全探索15!!
    ll ans = 0;
    vector<bool> used(N,false);
    function<ll(int)> dfs = [&](int v){
        // ベースケース: 最後の頂点を超えたら終了
        if(v >= N){
            return 0LL;
        }
        
        // 既に v が誰かとペアになっている場合は、次の頂点へ
        if(used[v]){
            return dfs(v+1);
        }
        ll res = 0;
        for(int nv = v+1; nv < N+cnt; nv++){
            if(used[nv]) continue;

            used[nv] = true;
            //cout << "v = " << v << " nv = " << nv << endl;
            res = max(res,dfs(v+1)+D[v][nv]);

            // バックトラック: 状態を元に戻す
            used[nv] = false;
        }
        return res;
    };

    cout << dfs(0) << endl;
}