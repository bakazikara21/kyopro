#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K; cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int l = -1, r = -1; // 反転している区間
    int ans = 0;
    for(int i = 0; i < N; i++){
        if((A[i] == 1 and (l > i or r < i)) or (A[i] == 0 and (l <= i and i <= r))){
            // K個連続する区間のビットを反転させる
            ans++;
            if(l == -1 and r == -1) l = i,r = i+K-1;
            else if(l <= i and i <= r) l = r+1,r = i+K-1;
            else l = i, r = i+K-1;
        }
        cout << "i = " << i << " left = " << l << " right = " << r << endl;
    }
    cout << ans << endl;
}
