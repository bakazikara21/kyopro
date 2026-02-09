#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
const int inf = (int)1e6;

/*
    同じ動物園は、多くても2回しか行かない
    3回以上行くと、同じ動物を3回見ることになり、無駄でしかないから
    3^10 -> 3ビット全探索
*/
int main(){
    int N,M;
    cin >> N >> M;
    vector<ll> cost(N);
    vector<vector<int>> zoo(N); // zoo[i] := i番目の動物園で見ることができる動物
    for(int i = 0; i < N; i++) cin >> cost[i];
    for(int i = 0; i < M; i++){
        int K;
        cin >> K;
        for(int j = 0; j < K; j++){
            int A;
            cin >> A;
            A--;
            zoo[A].push_back(i);
        }
    }
    ll ans = INF;
    int imax = (int)pow(3,N);
    for(int i = 0; i < imax; i++){
        ll precost = 0;
        bool ok = true;    // M種類の動物全てを2度以上見ることが可能ならtrue
        vector<int> cnt(M,0);
        int k = i;
        for(int bit = 0; bit < N; bit++){
            ll num = (k%3);
            // bit番目の動物園をnum回訪れる
            precost += cost[bit]*num;
            k /= 3;
            for(int j = 0; j < num; j++){
                for(int animal : zoo[bit]){
                    cnt[animal]++;
                }
            }
        }
        for(int j = 0; j < M; j++){
            if(cnt[j] <= 1){
                ok = false;
                break;
            }
        }
        if(ok) ans = min(ans,precost);
    }
    cout << ans << endl;
}