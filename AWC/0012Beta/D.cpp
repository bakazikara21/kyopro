#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
    pq.push({0,0,0});   // {破壊回数、行、列}
    vector<vector<bool>> used(N,vector<bool>(M,false));
    vector<int> di = {1,-1,0,0};
    vector<int> dj = {0,0,1,-1};
    while(!pq.empty()){
        auto [num,i,j] = pq.top(); pq.pop();
        if(used[i][j]) continue;
        used[i][j] = true;

        if(i == N-1 and j == M-1){
            cout << num << endl;
            break;
        }
        for(int k = 0; k < 4; k++){
            int ni = i+di[k];
            int nj = j+dj[k];
            if(ni < 0 or ni >= N or nj < 0 or nj >= M) continue;
            if(used[ni][nj]) continue;

            if(S[ni][nj] == '#') pq.push({num+1,ni,nj});
            else pq.push({num,ni,nj});
        }
    }
}
