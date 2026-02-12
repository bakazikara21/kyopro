#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> RL(M);
    for(int i = 0; i < M; i++){
        int l,r;
        cin >> l >> r;
        RL[i] = {r,l};
    }
    if(M > N){
        cout << "No" << endl;
        return 0;
    }
    sort(RL.begin(),RL.end());
    vector<bool> used(N+1,false);
    set<int> st;
    for(int i = 1; i <= N; i++){
        st.insert(i);
    }
    for(int i = 0; i < M; i++){
        auto [right,left] = RL[i];
        auto itr = st.lower_bound(left);
        if(itr == st.end() or *itr > right){
            cout << "No" << endl;
            return 0;
        }
        st.erase(itr);
    }
    cout << "Yes" << endl;
}
