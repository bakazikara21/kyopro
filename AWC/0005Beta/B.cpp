#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M,K;
    cin >> N >> M >> K;
    vector<int> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];
    for(int i = 0; i < M; i++){
        int P,V;
        cin >> P >> V;
        P--;
        S[P] = V;
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(S[i] < K) ans++;
    }
    cout << ans << endl;
}
