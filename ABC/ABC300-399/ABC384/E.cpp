#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int H,W,P,Q;
    ll X;
    cin >> H >> W >> X >> P >> Q;
    P--; Q--;
    // S[P][Q]はTakahashi
    ll takahashi = 0;
    vector<vector<ll>> S(H,vector<ll>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> S[i][j];
        }
    }
    set<pair<int,int>> used;
    priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>>> pq;
    pq.push({S[P][Q],P,Q});
    vector<int> di = {1,-1,0,0};
    vector<int> dj = {0,0,1,-1};
    while(!pq.empty()){
        auto [strong,i,j] = pq.top(); pq.pop();
        //cout << "i = " << i << " j = " << j << endl;
        if(used.count({i,j})) continue;
        if((i != P or j != Q)){
            if(takahashi%X == 0 and takahashi/X <= S[i][j]) continue;
            else if(takahashi%X != 0 and takahashi/X + 1 <= S[i][j]) continue;
        }
        used.insert({i,j});

        /*
        cout << "use : ";
        cout << "i = " << i << " j = " << j << endl;
        cout << "takahashi = " << takahashi << endl;
        */
        takahashi += strong;
        for(int k = 0; k < 4; k++){
            int ni = i+di[k];
            int nj = j+dj[k];

            if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
            if(used.count({ni,nj})) continue;
            pq.push({S[ni][nj],ni,nj});
        }
    }
    cout << takahashi << endl;
}
