#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> A(N);
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        pq.push({A[i],i});
    }
    vector<bool> used(N,false);
    ll ans = 0;
    while(!pq.empty()){
        auto [num,id] = pq.top(); pq.pop();
        if(used[id]) continue;
        used[id] = true;

        if(id+1 < N and used[id+1] == false and A[id]-A[id+1] > K){
            ans += A[id]-K-A[id+1];
            A[id+1] = A[id]-K;
            pq.push({A[id+1],id+1});
        }
        if(id-1 >= 0 and used[id-1] == false and A[id]-A[id-1] > K){
            ans += A[id]-K-A[id-1];
            A[id-1] = A[id]-K;
            pq.push({A[id-1],id-1});
        }
    }
    cout << ans << endl;
    /*
    for(int i = 0; i < N; i++){
        cout << A[i] << " ";
    }
    cout << endl;
    */
}
