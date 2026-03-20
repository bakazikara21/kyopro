#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ll N,a,b; cin >> N >> a >> b;
    vector<vector<ll>> dbl(41,vector<ll>(4));   // a-a,a-b,b-a,b-b
    /*
        ダブリング
    */
    dbl[0][0] = a/2;    // 直前にaがあるときに、aを選んだ時のスコア
    dbl[0][1] = b/2;
    dbl[0][2] = a;
    dbl[0][3] = b;
    int i = 1;
    while(i <= 40){
        // a始まりのa終わり
        dbl[i][0] = max(dbl[i-1][0]+dbl[i-1][0],dbl[i-1][1]+dbl[i-1][2]);

        // a始まりのb終わり
        dbl[i][1] = max(dbl[i-1][0]+dbl[i-1][1],dbl[i-1][1]+dbl[i-1][3]);

        // b始まりのa終わり
        dbl[i][2] = max(dbl[i-1][2]+dbl[i-1][0],dbl[i-1][3]+dbl[i-1][2]);

        // b始まりのb終わり
        dbl[i][3] = max(dbl[i-1][3]+dbl[i-1][3],dbl[i-1][2]+dbl[i-1][1]);
        i++;
    }
    i = 0;
    vector<ll> ans(4);
    while((N>>i) > 0){
        auto ans__ = ans;
        if((N>>i)&1){
            // a始まりのa終わり
            ans[0] = max(ans__[0]+dbl[i][0],ans__[1]+dbl[i][2]);

            // a始まりのb終わり
            ans[1] = max(ans__[0]+dbl[i][1],ans__[1]+dbl[i][3]);

            // b始まりのa終わり
            ans[2] = max(ans__[2]+dbl[i][0],ans__[3]+dbl[i][2]);

            // b始まりのb終わり
            ans[3] = max(ans__[3]+dbl[i][3],ans__[2]+dbl[i][1]);
        }
        i++;
    }
    cout << *max_element(ans.begin(),ans.end()) << endl;
}
