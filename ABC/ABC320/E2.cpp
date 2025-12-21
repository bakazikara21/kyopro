#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;

int main() {
    // 入出力の高速化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // 時刻timeに人numが返ってくる、時刻timeにそうめんが流される
    priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>>> pq; // {time,num}
    set<int> st;    // 人0~N-1を管理する
    for(int i = 0; i < N; i++){
        st.insert(i);
    }
    vector<ll> weigh(N, 0);
    vector<ll> T(M),W(M),S(M);
    for (int i = 0; i < M; i++) {
        cin >> T[i] >> W[i] >> S[i];
        
        pq.push({T[i],i,-1});   // 時刻timeにそうめんが流される
    }
    while(!pq.empty()){
        auto [tim,i,num] = pq.top(); pq.pop();
        if(st.size() > 0 and num == -1){
            // そうめんがながされるとき
            auto itr = st.begin();
            num = *itr;
            weigh[num] += W[i];
            pq.push({tim+S[i],-1,num});    // 時刻T+Sに人numが返ってくる
            st.erase(itr);
        }
        if(i == -1){
            // 時刻timに人numが返ってくるとき
            st.insert(num);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << weigh[i] << "\n";
    }

    return 0;
}