#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    set<int> damage;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++){
        int B;
        cin >> B;
        B--;
        damage.insert(B);
    }
    ll ans = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(damage.count(i) and A[i] < K){
            cnt++;
            ans += A[i];
        }
    }
    cout << cnt << " ";
    cout << ans << endl;
}
