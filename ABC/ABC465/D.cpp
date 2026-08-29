#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        ll X,Y,K; cin >> X >> Y >> K;
        // y = x/K or x*K <= y < (x+1)*K
        // なるyから自由に選べる
        // x > Y のうちは y = x/Kで必ず良い
        // x < Yになったら
        int ans = 0;
        while(X != Y){
            if(X > Y) X /= K;
            else Y /= K;
            ans++;
        }
        cout << ans << endl;
    }
}
