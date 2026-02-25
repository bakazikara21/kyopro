#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K,M; cin >> N >> K >> M;
    vector<int> experienced,non;
    for(int i = 0; i < N; i++){
        int H,P; cin >> H >> P;
        if(H == 1) experienced.push_back(P);
        else non.push_back(P);
    }
    sort(experienced.rbegin(),experienced.rend());
    sort(non.rbegin(),non.rend());
    if((int)experienced.size() < M or (int)non.size() < K-M){
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    for(int i = 0; i < M; i++){
        ans += experienced[i];
    }
    for(int i = 0; i < K-M; i++){
        ans += non[i];
    }
    cout << ans << endl;
}
