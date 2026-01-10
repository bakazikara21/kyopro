#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int N,W;
        cin >> N >> W;
        vector<ll> C(N);
        for(int i = 0; i < N; i++){
            cin >> C[i];
        }
        while((int)C.size() % (2*W) != 0){
            C.push_back(0);
        }
        for(int i = 0; i < W-1; i++){
            C.push_back(C[i]);
        }
        vector<ll> presum((int)C.size()+1);
        for(int i = 0; i < (int)C.size(); i++){
            presum[i+1] = presum[i]+C[i];
        }
        // W個連続するコストの区間和の(2W周期)の最小値
        if(N-W <= 0){
            cout << 0 << endl;
        }
        else{
            ll ans = INF;
            for(int i = 0; i < 2*W; i++){
                ll cost = 0;
                for(int j = i; W+j <= (int)C.size(); j+=2*W){
                    cost += presum[W+j]-presum[j];
                }
                // i ~ W-1+i, 2*W+i ~ 3*W-1+2*i, 
                ans = min(ans,cost);
            }
            cout << ans << endl;
        }
    }
}