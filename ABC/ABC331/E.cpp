#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M,L;
    cin >> N >> M >> L;
    vector<ll> a(N),b(M);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < M; i++) cin >> b[i];

    vector<pair<ll,int>> A(N),B(M);
    for(int i = 0; i < N; i++){
        A[i] = {a[i],i};
    }
    for(int i = 0; i < M; i++){
        B[i] = {b[i],i};
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    set<pair<int,int>> st,over;
    for(int i = 0; i < L; i++){
        int c,d;
        cin >> c >> d;
        c--; d--;
        st.insert({c,d});
    }

    // priority_queueでstに入っていない組み合わせを取ってきたら終了
    priority_queue<tuple<ll,int,int>> pq;
    vector<int> da = {-1,0};
    vector<int> db = {0,-1};
    ll amax = A[N-1].first;
    ll bmax = B[M-1].first;
    pq.push({amax+bmax,N-1,M-1});
   
    while(!pq.empty()){
        auto [val,aid,bid] = pq.top(); pq.pop();
        int ida = A[aid].second;
        int idb = B[bid].second;
        if(!st.count({ida,idb})){
            // 高々10^5回ループすれば答えに辿り着くのでTLEはあり得ないはず
            cout << val << endl;
            break;
        }
        for(int k = 0; k < 2; k++){
            int na = aid+da[k];
            int nb = bid+db[k];
            if(na < 0 or nb < 0) continue;
            if(over.count({na,nb})) continue;

            ll vala = A[na].first;
            ll valb = B[nb].first;
            pq.push({vala+valb,na,nb});
            over.insert({na,nb});
        }
    }
}
