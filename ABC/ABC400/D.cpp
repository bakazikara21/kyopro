#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
const int inf = (int)1e8;
/*
    
*/

// 
int main(){
    int H,W;
    cin >> H >> W;

    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];
    int si,sj,gi,gj;
    cin >> si >> sj >> gi >> gj;
    si--; sj--; gi--; gj--;
    vector<int> di = {1,-1,0,0};
    vector<int> dj = {0,0,1,-1};
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
    pq.push({0,si,sj});
    vector<vector<int>> dist(H,vector<int>(W,inf));
    while(!pq.empty()){
        auto [dis,i,j] = pq.top(); pq.pop();
        if(dist[i][j] < inf) continue;
        dist[i][j] = dis;
        if(i == gi and j == gj) break;

        for(int k = 0; k < 4; k++){
            int ni = i+di[k];   int nni = ni+di[k];
            int nj = j+dj[k];   int nnj = nj+dj[k];
            if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
            if(dist[ni][nj] < inf) continue;

            if(S[ni][nj] == '#'){
                // 壁のとき、
                pq.push({dis+1,ni,nj});
                if(nni < 0 or nni >= H or nnj < 0 or nnj >= W) continue;
                pq.push({dis+1,nni,nnj});
            }
            else pq.push({dis,ni,nj});
        }
    }
    cout << dist[gi][gj] << endl;
}