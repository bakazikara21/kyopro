#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int H,W;
    cin >> H >> W;
    vector<string> A(H);
    for(int i = 0; i < H; i++){
        cin >> A[i];
    }

    vector<vector<int>> grid(H,vector<int>(W));
    vector<vector<int>> potion(H,vector<int>(W));
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int R,C,E;
        cin >> R >> C >> E;
        R--; C--;
        potion[R][C] = E;
    }

    int si,sj,gi,gj;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] == 'S'){
                si = i;
                sj = j;
            }
            if(A[i][j] == 'T'){
                gi = i;
                gj = j;
            }
        }
    }
    priority_queue<tuple<int,int,int>> pq;
    pq.push({potion[si][sj],si,sj});
    potion[si][sj] = 0;
    vector<int> di = {0,-1,1,0};
    vector<int> dj = {1,0,0,-1};
    while(!pq.empty()){
        auto [ene,i,j] = pq.top(); pq.pop();

        if(ene <= 0) continue;
        
        for(int k = 0; k < 4; k++){
            int ni = i+di[k];
            int nj = j+dj[k];

            if(ni < 0 or ni >= H or nj < 0 or nj >= W) continue;
            if(A[ni][nj] == '#') continue;
            if(ni == gi and nj == gj){
                cout << "Yes" << endl;
                return 0;
            }
            /*
            if(potion[ni][nj] > 0){
                grid[ni][nj] = max(grid[ni][nj],potion[ni][nj]);
                potion[ni][nj] = 0;
                }
                ポーションがないのに隣接点のほうが値が大きいことはあり得ない
            */
            if(grid[ni][nj] > ene-1 and potion[ni][nj] == 0) continue;

            if(grid[ni][nj] < ene-1 and ene-1 >= potion[ni][nj]){
                // 隣接点の値より大きく、かつ、ポーションを使ったとしても下回らないとき
                // potionを拾わずに伝播させればよい
                grid[ni][nj] = ene-1;
                pq.push({ene-1,ni,nj});
                potion[ni][nj] = 0;
            }
            else if(grid[ni][nj] < potion[ni][nj] and potion[ni][nj] > ene-1){
                // ポーションを使えば、上回るとき、ポーションを使う
                pq.push({potion[ni][nj],ni,nj});
                grid[ni][nj] = potion[ni][nj];
                potion[ni][nj] = 0;
            }
        }
    }
    cout << "No" << endl;
    /*
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    */
}
