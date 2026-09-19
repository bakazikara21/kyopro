#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,D; cin >> N >> D;
    D = D*D;
    vector<bool> virus(N,false);
    virus[0] = true;
    vector<pair<int,int>> pos(N);
    for(int i = 0; i < N; i++){
        cin >> pos[i].first >> pos[i].second;
    }

    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int i = 0; i < N; i++){
            if(virus[i]) continue;

            int dist = (pos[v].first-pos[i].first)*(pos[v].first-pos[i].first) + 
                        (pos[v].second-pos[i].second)*(pos[v].second-pos[i].second);
            
            if(dist <= D){
                virus[i] = true;
                que.push(i);
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(virus[i]){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}
