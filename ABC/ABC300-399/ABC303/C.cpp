#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M,H,K; string S; cin >> N >> M >> H >> K >> S;
    map<pair<int,int>,int> mp;
    for(int i = 0; i < M; i++){
        int x,y; cin >> x >> y;
        mp[{x,y}] = K;
    }
    vector<int> dx = {+1,-1,0,0};
    vector<int> dy = {0,0,+1,-1};

    int x = 0, y = 0;
    int h = H;
    bool ok = true;
    for(int i = 0; i < N; i++){
        int nx = 0, ny = 0;
        for(int k = 0; k < 4; k++){
            if("RLUD"[k] == S[i]){
                nx = x+dx[k];
                ny = y+dy[k];
                break;
            }
        }
        x = nx;
        y = ny;
        h--;
        if(h < 0){
            ok = false;
            break;
        }
        if(h < K and mp.count({nx,ny}) and mp[{nx,ny}] == K){
            mp[{nx,ny}] = 0;
            h = K;
        }
    }
    if(ok){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}
