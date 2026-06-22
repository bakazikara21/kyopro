#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

bool isCovered(set<pair<int,int>> st, pair<int,int> p){
    auto [left,right] = p;
    
};
int calc(set<pair<int,int>> st){
    int ret = 0;
    auto itr = st.begin();
    while(next(itr) != st.end()){
        int right = itr->second;
        int left = next(itr)->first;
        ret += (left-right);
        itr++;
    }
    return ret;
}
int main(){
    int N,K; cin >> N >> K;
    vector<int> l(N),r(N);
    vector<pair<int,int>> L(N),R(N),LR(N);
    for(int i = 0; i < N; i++){
        // [L,R]の区間の長さが小さいやつを選ぶとよい
        // 左端はRの最小値となる布
        // 右端はLの最大値となる布
        cin >> l[i] >> r[i];
        
        L[i].first = l[i];
        R[i].first = r[i];
        L[i].second = i;
        R[i].second = i;
        LR[i] = {R[i].first-L[i].first,i};
    }
    sort(R.begin(),R.end());
    sort(L.rbegin(),L.rend());
    sort(LR.begin(),LR.end());
    int leftID = R[0].second;
    int rightID = L[0].second;  // 右端のIndex
    if(rightID == leftID or R[0].first >= L[0].first){
        cout << -1 << endl;
        return 0;
    }
    set<pair<int,int>> st;
    st.insert({l[leftID],r[leftID]});
    st.insert({l[rightID],r[rightID]});
    for(int i = 0; i < N; i++){
        int k = (int)st.size();
        if(k == K) break;
        auto [dif,id] = LR[i];
        if(id == leftID or id == rightID) continue;
        if(isCovered(st,{l[i],r[i]})) continue;

        st.insert({l[i],r[i]});
    }
    int k = (int)st.size();
    if(k == K){
        int num = calc(st);
    }
}
