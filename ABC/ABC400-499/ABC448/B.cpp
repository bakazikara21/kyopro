#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    int ans = 0;
    vector<int> C(M);
    for(int i = 0; i < M; i++) cin >> C[i];
    for(int i = 0; i < N; i++){
        int A,B; cin >> A >> B;
        A--;
        if(C[A] >= B){
            ans += B;
            C[A] -= B;
        }
        else{
            ans += C[A];
            C[A] = 0;
        }
    }
    cout << ans << endl;
}
