#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> C(N),R(M);
    for(int i = 0; i < N; i++) cin >> C[i];
    for(int i = 0; i < M; i++) cin >> R[i];
    sort(C.begin(),C.end());
    sort(R.begin(),R.end());

    int now = N-1, ans = 0;
    for(int i = M-1; i >= 0; i--){
        while(now >= 0 and R[i] < C[now]){
            now--;
        }
        if(now >= 0 and R[i] >= C[now]){
            ans++;
            now--;
        }
    }
    cout << ans << endl;
}
