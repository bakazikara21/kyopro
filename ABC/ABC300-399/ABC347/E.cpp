#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,Q;
    cin >> N >> Q;

    vector<vector<pair<int,int>>> staend(N);
    vector<ll> A(N);
    vector<ll> presum(Q+1);
    set<int> st;
    for(int q = 0; q < Q; q++){
        int x;
        cin >> x; x--;

        if(st.count(x)){
            int len = (int)staend[x].size();
            staend[x][len-1].second = q;
            st.erase(x);
        }
        else {
            st.insert(x);
            staend[x].push_back({q+1,-1});
        }

        int siz = (int)st.size();
        presum[q+1] = presum[q] + siz;
    }
    for(int i = 0; i < N; i++){
        for(auto [sta,end] : staend[i]){
            // 1 <= sta,end <= Q
            if(end > 0){
                A[i] += presum[end]-presum[sta-1];
            }
            else{
                A[i] += presum[Q]-presum[sta-1];
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}
