#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,Q; cin >> N >> Q;
    vector<int> P(N);
    for(int &p : P) cin >> p;
    set<int> st;
    vector<int> a(Q);
    for(int q = 0; q < Q; q++){
        cin >> a[q];
    }
    for(int q = Q-1; q >= 0; q--){
        if(st.count(a[q])) continue;
        P.push_back(a[q]);
        st.insert(a[q]);
    }
    reverse(P.begin()+N,P.end());
    for(int i = 0; i < P.size(); i++){
        if(i < N and st.count(P[i])){
            continue;
        }
        else cout << P[i] << " ";
    }
    cout << endl;
}
