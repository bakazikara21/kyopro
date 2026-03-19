#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,P,B,K; cin >> N >> P >> B >> K;
    int ans = 0;
    for(int i = 0; i < N; i++){
        int C; cin >> C;
        if(C >= K){
            ans += (P+B)*(C);
        }
        else ans += C*P;
        
    }
    cout << ans << endl;
}
