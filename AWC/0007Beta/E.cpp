#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

/*
    巡回セールスマン問題をbitDPで解くやつ
    dp[mask] := マスの集合をmaskとして、始点からmaskに行くまでの最小移動回数
*/
int main(){
    int N,M; ll S,T;
    cin >> N >> M >> S >> T;
    vector<pair<ll,ll>> P(M);
    for(int i = 0; i < M; i++){
        ll num;
        cin >> num;
        ll X = (num-1)/N;
        ll Y = num%N -1;
        if(Y < 0) Y += N;
        P[i] = {X,Y};
    }
    /*
        dp[1111] = min(dp[1110][now]+now->0001, dp[1101][now]+now->0010, ...);
    */
    int maskmax = (1 << M);
    vector<vector<ll>> dp(maskmax,vector<ll>(M,INF));   // dp[すでに通過した場所][現在地]
    ll sx = (S-1)/N;
    ll sy = (S%N)-1;
    if(sy < 0) sy += N;
    ll gx = (T-1)/N;
    ll gy = (T%N)-1;
    if(gy < 0) gy += N;
    if(M == 0){
        cout << abs(sx-gx)+abs(sy-gy) << endl;
        return 0;
    }
    for(int i = 0; i < M; i++){
        int nmask = (1<<i);
        ll nx = P[i].first;
        ll ny = P[i].second;
        dp[nmask][i] = abs(sx-nx) + abs(sy-ny);
    }
    for(int mask = 1; mask < maskmax; mask++){
        // 配るdpのほうが書きやすい
        for(int i = 0; i < M; i++){
            if((mask & (1<<i)) > 0) continue;
            int nmask = (1<<i) | mask;
            ll nx = P[i].first;
            ll ny = P[i].second;
            
            for(int j = 0; j < M; j++){
                // j->iに行く
                if(i == j) continue;
                if(dp[mask][j] == INF) continue;
                ll x = P[j].first;
                ll y = P[j].second;
                dp[nmask][i] = min(dp[nmask][i] ,abs(x-nx) + abs(y-ny) + dp[mask][j]);
            }
        }
    }
    ll ans = INF;
    for(int i = 0; i < M; i++){
        ll nx = P[i].first;
        ll ny = P[i].second;
        ans = min(ans,dp[maskmax-1][i]+abs(nx-gx)+abs(ny-gy));
    }
    cout << ans << endl;
}
