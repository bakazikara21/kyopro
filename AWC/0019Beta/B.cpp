#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K; cin >> N >> K;
    int ans = 0;
    for(int i = 0; i < N; i++){
        string S; cin >> S;
        int M = (int)S.size();
        int cnt = 0;
        for(int j = 0; j < M; j++){
            if(S[j] == '!') cnt++;
        }
        if(cnt >= K) ans++;
    }
    cout << ans << endl;
}
