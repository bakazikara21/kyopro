#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        int N; cin >> N; 
        vector<ll> A(N),B(N);
        vector<pair<int,int>> dif(N);
        ll ans = 0;
        ll cost_cp = INF;
        for(int i = 0; i < N; i++){
            cin >> A[i] >> B[i];
            dif[i] = {B[i]-A[i],i};
            ans += A[i];
            cost_cp = min(cost_cp,A[i]);
        }
        sort(dif.begin(),dif.end());
        int cp = N;
        /*
            順番関係ないなら
            A[i]-B[i]の大きい順にB[i]で、
            A[i]-B[i]の小さい順にA[i]で、
            商品を購入すればよい
            クーポン目当てなら、最安のA[i]だけを選べばよい
            そのA[i]が B[t]-A[t] の価値があるのかどうか
            A[i] + B[t]-A[t] >= 0 なら終了
        */
        for(int i = 0; i < N; i++){
            if(cp <= 1){
                if(cp == 1 and dif[i].first + cost_cp < 0){
                    cp = 0;
                    ans += dif[i].first + cost_cp;
                }
                else if(cp == 0 and dif[i].first + 2*cost_cp < 0){
                    ans += dif[i].first + 2*cost_cp;
                }
                else break;
                continue;
            }
            ans += dif[i].first;
            cp -= 2;
        }
        cout << ans << endl;
    }
}
