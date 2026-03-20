#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    vector<ll> P(M);
    for(int i = 0; i < M; i++) cin >> P[i];
    for(int i = 0; i < N; i++){
        int K; cin >> K;
        int ans = 0;
        int mx = 0;
        for(int k = 0; k < K; k++){
            int C; cin >> C; C--;
            if(mx < P[C]){
                ans = C+1;
                mx = P[C];
            }
            else if(mx == P[C]){
                ans = min(ans,C+1);
            }
        }
        cout << ans << endl;
    }
}
