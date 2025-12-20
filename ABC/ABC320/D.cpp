#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
int main(){
    int N,M;
    cin >> N >> M;
    vector<pair<ll,ll>> pos(N,{INF,INF});
    pos[0] = {0,0};
    vector<vector<tuple<int,ll,ll>>> tab(N);
    for(int i = 0; i < M; i++){
        int A,B;
        ll X,Y;
        cin >> A >> B >> X >> Y;
        A--; B--;
        tab[A].push_back({B,X,Y});
        tab[B].push_back({A,-X,-Y});
    }
    queue<int> que;
    que.push(0);
    vector<bool> used(N,false);
    used[0] = true;
    while(!que.empty()){
        int num = que.front(); que.pop();

        ll x = pos[num].first;
        ll y = pos[num].second;
        for(auto [i,rx,ry] : tab[num]){
            if(used[i]) continue;

            used[i] = true;
            ll nx = x + rx;
            ll ny = y + ry;
            pos[i] = {nx,ny};
            que.push(i);
        }
    }
   
    for(int i = 0; i < N; i++){
        ll x = pos[i].first;
        ll y = pos[i].second;
        if(x == INF or y == INF){
            cout << "undecidable" << endl;
            continue;
        }
        cout << x << " " << y << endl;
    }
}
