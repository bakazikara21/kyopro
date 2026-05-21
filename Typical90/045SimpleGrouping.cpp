#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)3e18;
const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;

/*
    bitDP + 部分集合の部分集合を全列挙
*/
ll dist(pair<ll,ll> p, pair<ll,ll> q){
    return (p.first - q.first)*(p.first - q.first) + (p.second - q.second)*(p.second - q.second);
}
int main(){
    int N,K; cin >> N >> K;
    vector<pair<ll,ll>> P(N);
    for(int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;

    // はじめにbit全探索で各部分集合の2点間距離の最大値を求める。
    int MASK = (1<<N);
    vector<ll> cost(MASK);
    for(int mask = 1; mask < MASK; mask++){
        vector<int> ids;
        for(int bit = 0; bit < N; bit++){
            if((mask >> bit) & 1){
                ids.push_back(bit);
            }
        }

        int M = (int)ids.size();
        for(int i = 0; i < M; i++){
            for(int j = i+1; j < M; j++){
                // P[i]とP[j]の距離
                cost[mask] = max(cost[mask],dist(P[ids[i]],P[ids[j]]));
            }
        }
    }
    // dp[k][mask] := maskをk個のグループに分けたときの各グループの2点間距離の最大値の最小値
    vector<vector<ll>> dp(K+1,vector<ll>(1<<N,INF));
    for(int k = 0; k <= K; k++) dp[k][0] = 0;
    for(int mask = 0; mask < MASK; mask++){
        dp[1][mask] = cost[mask];
    }
    /*
        dp[k][mask] = min(max(dp[k-1][mask/S],cost[S]),dp[k][mask]);
    */
    for(int k = 2; k <= K; k++){
        for(int mask = 1; mask < MASK; mask++){
            // このmaskの部分集合を全列挙する
            for(int S = mask; S > 0; S = (S-1)&mask){
                dp[k][mask] = min(max(dp[k-1][mask ^ S],cost[S]), dp[k][mask]);
            }
            // Sは必ずmaskの部分集合である。なぜなら S = (S-1)&mask だから
            // Sは必ず相異なる部分集合を作る。なぜなら (S-1)&mask < S だから
            // Sは必ず全ての部分集合を網羅できる。
            /*
                (S-1)&maskがSの次に小さい部分集合であることを示せばよい。
                直感的にS未満でかつmaskの部分集合の最大値は(S-1)&maskで求まりそう。
            */
        }
    }
    cout << dp[K][MASK-1] << endl;
}