#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K,M; cin >> N >> K >> M;
    vector<pair<ll,int>> cmax(N);
    vector<tuple<ll,ll,int>> val(N);
    vector<bool> used(N,false);
    for(int i = 0; i < N; i++){
        int c; ll v; cin >> c >> v;
        c--;
        if(cmax[c].first < v){
            cmax[c].first = v;
            cmax[c].second = i;
        }
        val[i] = {v,c,i};
    }
    sort(cmax.rbegin(),cmax.rend());
    sort(val.rbegin(),val.rend());
    ll ans = 0;
    for(int i = 0; i < M; i++){
        ans += cmax[i].first;
        used[cmax[i].second] = true;
    }
    // 残りからK-M個選べば終わり
    int cnt = 0;
    int i = 0;
    while(cnt < K-M){
        auto [v,c,id] = val[i];

        if(used[id] == false){
            cnt++;
            ans += v;
        }
        i++;
    }
    cout << ans << endl;
}
