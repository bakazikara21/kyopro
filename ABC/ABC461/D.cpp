#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

ll ijo(vector<ll> B, ll K){
    // B[r]-B[l] >= Kなるr,lの個数をO(W+W)で求める
    // r > l , r == lだと列なし
    int W = (int)B.size();  W--;
    ll cnt = 0;
    int r = 1;
    for(int l = 0; l < W; l++){
        r = max(r,l+1);
        while(r <= W and B[r] < B[l] + K){
            r++;
        }
        if(r <= W and B[r] >= B[l] + K){
            cnt += W-r+1;
        }
    }
    return cnt;
}
ll dainari(vector<ll> B, ll K){
    // B[r]-B[l] > Kなるr,lの個数をO(W+W)で求める
    int W = (int)B.size();  W--;
    ll cnt = 0;
    int r = 1;
    for(int l = 0; l < W; l++){
        r = max(r,l+1);
        while(r <= W and B[r] <= B[l] + K){
            r++;
        }
        if(r <= W and B[r] > B[l] + K){
            cnt += W-r+1;
        }
    }
    return cnt;
}
int main(){
    ll H,W,K; cin >> H >> W >> K;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    // 長方形の上辺と下辺を固定して、各列の1の個数を高速に求められるようにimos。
    vector<vector<int>> imos(H+1,vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '1') imos[i+1][j] = 1;
        }
    }

    for(int j = 0; j < W; j++){
        for(int i = 1; i < H; i++){
            imos[i+1][j] += imos[i][j]; // 列ごとの累積和だけ出しておく。
        }
    }

    ll ans = 0;
    for(int r1 = 0; r1 < H; r1++){
        for(int r2 = r1; r2 < H; r2++){
            // 長方形の上辺と下辺を(r1,?),(r2,?)で固定。
            // 長方形(r1,c1),(r2,c2)の整数の合計がKとなる(c1,c2)の個数をO(W)で解く。
            vector<ll> B(W+1);  // 上下が固定された状態の各列の累積和
            for(int l = 0; l < W; l++){
                // 尺取り法で左端固定して右端をO(W+W)で求めればよい。
                // B[r]-B[l] >= Kなるr,lの個数 - B[r]-B[l] > Kなるr,lの個数
                // どちらともO(W+W)で求められそう
                B[l+1] = B[l] + imos[r2+1][l]-imos[r1][l];
            }
            ll ijou = ijo(B,K);
            ll dai = dainari(B,K);
            ans += (ijou - dai);
        }
    }
    cout << ans << endl;
}
