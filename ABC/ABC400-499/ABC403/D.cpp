#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
const int inf = (int)1e6;

int main(){
    int N,D;
    cin >> N >> D;
    
    vector<int> A(N),cnt(inf+1);
    set<int> st;
    int maxA = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        cnt[A[i]]++;
        maxA = max(maxA,A[i]);
        st.insert(A[i]);
    }
    if(D == 0){
        cout << N-(int)st.size() << endl;
        return 0;
    }
    vector<int> dp(maxA+1);  // dp[kD] := 0,D,2D,...,kD までの最小の削除数
    /*
        dp[kD] := min(dp[(k-1)D]+(kDの個数),dp[(k-2)D]+((k-1)Dの個数))
    */
    int ans = 0;
    for(int i = 0; i < D; i++){
        int j = i;
        if(j > maxA) break;
        while(j <= maxA){
            if(j < D){
                dp[j] = 0;
            }
            else if(j < 2*D){
                dp[j] = min(cnt[j],cnt[j-D]);
            }
            else dp[j] = min(dp[j-D]+cnt[j],dp[j-2*D]+cnt[j-D]);
            j += D;
        }
        j -= D;
        //cout << "i = " << i << " j = " << j << endl; 
        ans += dp[j];
    }
    cout << ans << endl;
}