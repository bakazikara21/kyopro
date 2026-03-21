#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M,K,T; cin >> N >> M >> K >> T;
    vector<int> prefix(N+1);
    for(int i = 0; i < M; i++){
        int B; cin >> B;
        prefix[B]++;
    }
    for(int i = 0; i < N; i++){
        prefix[i+1] += prefix[i];
    }
    for(int k = 0; k < K; k++){
        int L,R; cin >> L >> R;
        if(prefix[R]-prefix[L-1] >= T){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}
