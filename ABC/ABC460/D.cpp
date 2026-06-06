#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int H,W; cin >> H >> W;
    vector<string> S(H),T(H);
    for(int i = 0; i < H; i++) cin >> S[i],T[i] = S[i];
    
    /*
        白マスと黒マスが八近傍にあるならば、
        その白マスと黒マスは交互に白->黒->白->...を永遠に繰り返すことが確定する。
        ->だからなに？

        黒マスから白マスに対してbfsを行うと、(黒を0として)
        始めて黒マスになるのが何ターン目かがわかる。
        距離の絶対値が1である点は、交互に白黒になるのが確定する。
        隣接点がない点は、必ず白になる。で終わりか。
        1回シミュレーションを行うと、黒マスのまわりには必ず白マスが存在することがわかる。
        黒マスのみの3*3のマスがあると、その真ん中のマスが確定しないので厄介。
        なので1回シミュレーションを行うと簡単に解ける。
    */
    // 以下、1回シミュレーションを行う。
    vector<int> di = {1,-1,0,0,1,1,-1,-1};
    vector<int> dj = {0,0,1,-1,1,-1,1,-1};
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '#'){
                T[i][j] = '.';
                continue;
            }
            for(int k = 0; k < 8; k++){
                int ni = i + di[k];
                int nj = j + dj[k];
                if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue; 

                if(S[ni][nj] == '#'){
                    T[i][j] = '#';
                    break;
                }
            }
        }
    }

    // ここから、bfsからの偶奇で判定。
    vector<vector<int>> dist(H,vector<int>(W,inf)); // 黒マスからの最短距離
    queue<pair<int,int>> que;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(T[i][j] == '#') {que.push({i,j}); dist[i][j] = 0;} // 黒マスをペア型でプッシュする
        }
    }
    while(!que.empty()){
        auto [i,j] = que.front(); que.pop();
        int d = dist[i][j];
        for(int k = 0; k < 8; k++){
            int ni = i + di[k];
            int nj = j + dj[k];
            if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
            if(T[ni][nj] == '#') continue;

            if(dist[ni][nj] < inf) continue;
            dist[ni][nj] = d+1;
            que.push({ni,nj});
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            // 各マスの8近傍を見て、隣接マスが存在するかどうか
            int here = dist[i][j];
            
            if((here%2) == 0){
                cout << '.';    // 偶数なら白マスになる
            }
            else cout << '#';   // 奇数なら黒マスになる
        }
        cout << endl;
    }
}
