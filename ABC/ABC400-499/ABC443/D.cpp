#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int N;
        cin >> N;
        vector<ll> row(N);
 
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        for(int i = 0; i < N; i++){
            cin >> row[i];
            pq.push({row[i],i});
        }
        vector<bool> used(N,false);
        ll ans = 0;
        vector<int> dj = {1,-1};
        while(!pq.empty()){
            auto [mini,id] = pq.top(); pq.pop();
            if(used[id] == true) continue;
            used[id] = true;
            
            for(int k = 0; k < 2; k++){
                int nj = id+dj[k];
                if(nj < 0 or nj >= N) continue;
                if(used[nj]) continue;

                if(row[nj] > row[id]){
                    ans += row[nj] - (row[id]+1);
                    row[nj] = row[id]+1;
                }
                pq.push({row[nj],nj});
            }
        }
        cout << ans << endl;
    }
}
