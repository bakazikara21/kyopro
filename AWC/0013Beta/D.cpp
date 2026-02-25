#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    vector<vector<ll>> A(N,vector<ll>(M));
    vector<vector<ll>> vec(M,vector<ll>(N));    // 要素N個の配列がM個
    vector<ll> sum(M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> A[i][j];
            vec[j][i] = A[i][j];
        }
    }
    ll ans = 0;
    for(int i = 0; i < M; i++){
        sort(vec[i].begin(),vec[i].end());
        sum[i] = accumulate(vec[i].begin(),vec[i].end(),0LL);
        for(int j = 0; j < N; j++){
            sum[i] -= vec[i][j];
            ans += sum[i];
            ans -= vec[i][j]*(N-j-1);
        }
    }
    cout << ans << endl;
}
