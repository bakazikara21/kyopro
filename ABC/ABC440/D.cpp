#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e10;

int main(){
    int N,Q;
    cin >> N >> Q;
    vector<ll> A(N),covered(N+1);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    vector<pair<ll,ll>> st(N+1);
    for(int i = 0; i < N; i++){
        if(i == 0){
            st[i] = {1LL,A[0]-1};
            covered[i] = A[0]-1;
        }
        else{
            st[i] = {A[i-1]+1,A[i]-1};
            covered[i] = A[i]-A[i-1]-1 + covered[i-1];
        }
    }
    st[N] = {A[N-1]+1,INF};
    covered[N] = INF-A[N-1]-1 + covered[N-1];
    for(int q = 0; q < Q; q++){
        ll X,Y;
        cin >> X >> Y;
        int t = lower_bound(st.begin(),st.end(),make_pair(X, -1LL)) - st.begin();
        ll cnt = 0;
        if(t > 0 and st[t-1].second >= X) cnt += st[t-1].second - X + 1;   // 区間にあるX以上の整数の個数
        t = lower_bound(covered.begin() + t,covered.end(),Y-covered[t-1])-covered.begin();
        cout << "count = " << cnt << " covered[t] = " << covered[t]-covered[t-1] << endl;
    }
}