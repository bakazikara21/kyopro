#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    vector<pair<ll,ll>> PT(N);
    for(int i = 0; i < N; i++){
        ll P,T; cin >> P >> T;
        PT[i] = {P,T};
    }
    for(int i = 0; i < M; i++){
        int K; cin >> K;
        ll minN = INF;
        ll minY = INF;
        for(int k = 0; k < K; k++){
            int S; cin >> S; S--;
            auto [money,type] = PT[S];
            if(type == 0){
                minY = min(minY,money);
            }
            else minN = min(minN,money);
        }
        if(minN == INF or minY == INF){
            cout << -1 << endl;
        }
        else cout << minN + minY << endl;
    }
}
