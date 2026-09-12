#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    vector<int> cnt(N);
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
    int ans = 0;
    for(int i = 0; i < N; i++){
        int a,d,b; cin >> a >> d >> b;
        a--; b--;
        pq.push({d,a,b});
        if(cnt[a] == 0) ans++;
        cnt[a]++;
    }
    for(int j = 1; j <= M; j++){
        while(true){
            if(pq.empty()) break;
            auto [D,A,B] = pq.top();
            if(D != j) break;
            pq.pop();
            cnt[A]--;
            if(cnt[A] == 0){
                ans--;
            }
            if(cnt[B] == 0){
                ans++;
            }
            cnt[B]++;
        }
        cout << ans << endl;
    }
}
