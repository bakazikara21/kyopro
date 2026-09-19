#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int W,H,N; cin >> W >> H >> N;

    // ピースの座標は高々N個
    map<pair<int,int>,int> mp;  // ピースの座標に対するケーキの個数
    vector<pair<int,int>> pos(N);
    for(int i = 0; i < N; i++){
        cin >> pos[i].first >> pos[i].second;
    }
    int A; cin >> A;
    vector<int> a(A);
    for(int i = 0; i < A; i++){
        cin >> a[i];
    }
    int B; cin >> B;
    vector<int> b(B);
    for(int i = 0; i < B; i++){
        cin >> b[i];
    }

    int mx = 0;
    for(int i = 0; i < N; i++){
        auto [x,y] = pos[i];
        int tx = lower_bound(a.begin(),a.end(),x)-a.begin();
        int ty = lower_bound(b.begin(),b.end(),y)-b.begin();

        mp[{tx,ty}]++;
        mx = max(mx,mp[{tx,ty}]);
    }

    int mn = inf;
    if(1LL * mp.size() < 1LL*(A+1)*(B+1)){
        mn = 0;
    }

    for(auto [key,val] : mp){
        mn = min(mn,val);
    }

    cout << mn << " " << mx << endl;
}
