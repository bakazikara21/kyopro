#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
int main(){
    int N;
    ll D;
    cin >> N >> D;
    vector<ll> A(N);
    set<pair<ll,ll>> st;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    int r = 0;
    ll ans = 0;
    for(int i = 0; i < N; i++){
        st.insert({A[i]-(D-1),A[i]+(D-1)});
        r = max(r,i);
        // A[i]が左端のとき、rはどこまでいけるか
        while(r+1 < N and abs(A[r]-A[r+1]) >= D){
            // r+1が左端の候補になる
            // A[r+1]が範囲のどこにもかぶっていなかったらok
            bool ok = true;
            auto itr = st.lower_bound({A[r+1],-1});
            if(itr == st.end()){
                itr = prev(itr);
            }
            if(itr->first > A[r+1] and itr != st.begin()){
                itr = prev(itr);
            }
            // cout << "i = " << i << " r = " << r << endl;
            // cout << "first = " << itr->first << " second = " << itr->second << endl;
            if(itr->first <= A[r+1] and A[r+1] <= itr->second){
                ok = false;
            }
            if(ok == false){
                break;
            }
            st.insert({A[r+1]-(D-1),A[r+1]+(D-1)});
            r++;
        }
        ans += (r-i+1);
        st.erase({A[i]-(D-1),A[i]+(D-1)});
    }
    cout << ans << endl;
}
