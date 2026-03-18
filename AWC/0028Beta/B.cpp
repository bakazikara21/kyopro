#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,L,R; cin >> N >> L >> R;
    vector<int> T(N);
    for(int i = 0; i < N; i++) cin >> T[i];
    int ans = 0;
    int right = 0;
    for(int left = 0; left < N; left++){
        right = max(right,left);
        if(T[left] < L or T[left] > R) continue;
        while(right+1 < N and L <= T[right+1] and T[right+1] <= R){
            right++;
        }
        ans = max(ans,right-left+1);
    }
    cout << ans << endl;
}
