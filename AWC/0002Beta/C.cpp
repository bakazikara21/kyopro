#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M;
    cin >> N >> M;

    int ans = 0;
    for(int i = 0; i < N; i++){
        int A,B;
        cin >> A >> B;
        if(A >= M){
            continue;
        }
        if((M-A)%B == 0){
            ans = max(ans,(M-A)/B);
        }
        else ans = max(ans,(M-A)/B + 1);
    }
    cout << ans << endl;
}
