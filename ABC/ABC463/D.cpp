#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

bool isCovered(set<pair<ll,ll>> st, pair<ll,ll> p){

};
int main(){
    int N,K; cin >> N >> K;
    vector<pair<ll,ll>> L(N),R(N),LR(N);
    for(int i = 0; i < N; i++){
        // [L,R]の区間の長さが小さいやつを選ぶとよい
        // 左端はRの最小値となる布
        // 右端はLの最大値となる布
        cin >> L[i].first >> R[i].first;
        L[i].second = i;
        R[i].second = i;
        LR[i] = {R[i].first-L[i].first,i};
    }
    sort(R.begin(),R.end());
    sort(L.rbegin(),L.rend());
    sort(LR.begin(),LR.end());
    int rightID = R[0].second;
    int leftID = L[0].second;
    if(rightID == leftID){
        cout << -1 << endl;
        return 0;
    }


}
