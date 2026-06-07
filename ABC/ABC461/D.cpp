#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int H,W,K; cin >> H >> W >> K;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    // 左上の頂点を固定して、高速で右下の頂点を探す。
    vector<vector<int>> imos(H,vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '1') imos[i][j] = 1;
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 1; j < W; j++){
            imos[i][j] += imos[i][j-1]; // 行ごとの累積和だけ出しておく。
        }
    }

    ll ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            // 左上の頂点を(i,j)で固定。
            int minus = 0;    // 二分探索のマイナス値
            int right = W-1;
            for(int k = i; k < H; k++){
                // 右下の頂点の行をkとしたときに
                // 二分探索+尺取りで列を求める。
                if(j >= 1) minus += imos[k][j-1];
                ll t = upper_bound(imos[k].begin(),imos[k].end(),K-minus)-lower_bound(imos[k].begin(),imos[k].end(),K-minus);
                ans += t;

            }
        }
    }
    cout << ans << endl;
}
