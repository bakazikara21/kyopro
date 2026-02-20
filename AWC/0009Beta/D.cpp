#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M;
    cin >> N >> M;  // max = 1e18 + N;
    vector<pair<ll,ll>> LR(M);
    for(int i = 0; i < M; i++){
        ll L,R;
        cin >> L >> R;
        LR[i] = {L,R};
    }
    sort(LR.begin(),LR.end());
    ll now = 1;
    ll cnt = 0;
    for(int i = 0; i < M; i++){
        auto [left,right] = LR[i];
        if(now < left){
            // left-1まで行けるで
            if(cnt + left - now >= N){
                ll dif = (N - cnt);
                cout << now -1 + dif << endl;
                return 0;
            }
            else cnt += (left-now);
        }
        now = max(now,right+1);
    }
    ll dif = (N-cnt);
    cout << now-1 + dif << endl;
}
