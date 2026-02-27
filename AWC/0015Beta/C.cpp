#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<map<int,ll>> vec(100000+1);
    for(int i = 0; i < N; i++){
        int P,Q; cin >> P >> Q;
        vec[P][Q]++;
    }
    ll ans = 0;
    for(int i = 1; i <= 100000; i++){
        ll sum = 0;
        for(auto [key,val] : vec[i]){
            sum += val;
        }
        for(auto [key,val] : vec[i]){
            sum -= val;
            ans += val*sum;
        }
    }
    cout << ans << endl;
}
