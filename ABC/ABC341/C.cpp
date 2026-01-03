#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int H,W,N;
    cin >> H >> W >> N;

    string T;
    cin >> T;
    
    vector<string> S(H);
    for(int i = 0; i < H; i++){
        cin >> S[i];    // gridの島
    }

    vector<int> dx = {0,0,-1,1};
    vector<int> dy = {-1,1,0,0};
    map<char,int> mp;
    mp['L'] = 0;
    mp['R'] = 1;
    mp['U'] = 2;
    mp['D'] = 3;

    int ans = 0;
    for(int i = 1; i < H-1; i++){
        for(int j = 1; j < W-1; j++){
            // (i,j)をスタート地点として全探索
            bool ok = true;
            
            int kmax = (int)T.size();
            int x = i;
            int y = j;
            if(S[x][y] == '#') continue;
            for(int k = 0; k < kmax; k++){
                char c = T[k];
                int num = mp[c];

                int nx = x+dx[num];
                int ny = y+dy[num];

                if(S[nx][ny] == '#'){
                    ok = false;
                    break;
                }
                x = nx;
                y = ny;
            }
            if(ok){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
