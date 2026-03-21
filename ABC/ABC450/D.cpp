#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ll N,K; cin >> N >> K;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(),A.end());
    ll mx = A[N-1];
    for(int i = 0; i < N-1; i++){
        // 最大値に近づかせる
        ll x = (mx-A[i])/K;
        A[i] += K*x;
    }
    sort(A.begin(),A.end());
    ll ans = A[N-1]-A[0];
    deque<ll> deq;
    for(int i = 0; i < N; i++){
        deq.push_back(A[i]);
    }
    for(int i = 0; i < N; i++){
        ll ft = deq.front(); deq.pop_front();
        ft += K;
        deq.push_back(ft);
        ll mn = deq.front(); 
        ans = min(ans,ft-mn);
    }
    cout << ans << endl;
}
