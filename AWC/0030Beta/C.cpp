#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K; cin >> N >> K;
    vector<int> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];
    int r = 0, ans = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 0) continue;
        r = max(r,i);
        while(r+1 < N and S[r+1] == 1){
            r++;
        }
        if((r-i+1) >= K){
            ans++;
            i = r;
        }
    }
    cout << ans << endl;
}
