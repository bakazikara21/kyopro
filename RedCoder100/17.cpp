#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const int inf = 1e9;
const ll mod = 1e9 + 7;

int main(){
    int k;
    cin >> k;
    vector<pair<int,int>> chess(k);
    for(int i = 0; i < k; i++){
        int r,c;
        cin >> r >> c;
        chess[i] = {r,c};
    }
    
    // 残り8-k個のチェスの置き場所を決める
    // 0から7行目まで一個ずつしか置けない
    // 0から7列目まで一個ずつしか置けない
    vector<int> pos(8);
    for(int i = 0; i < 8; i++){
        pos[i] = i;
    }
    vector<pair<int,int>> vir_chess(8);
    do{
        for(int i = 0; i < 8; i++){
            // i行目のどの列に置くかは順列全探索
            vir_chess[i] = {i,pos[i]};
        }
        bool ok = true;
        for(auto [x,y] : chess){
            if(vir_chess[x].second != y){
                // 条件として与えられているチェス盤と違ったらダメ！
                ok = false;
                break;
            }
        }
        // さらに斜めもそろってはダメです
        for(int i = 0; i < 8; i++){
            auto [x,y] = vir_chess[i];
            for(int j = 0; j < 8; j++){
                if(i == j) continue;
                auto [nx,ny] = vir_chess[j];
                if(abs(x-nx) == abs(y-ny)){
                    // 斜めに他のクイーンが存在している場合
                    ok = false;
                    break;
                }
            }
            if(!ok){
                break;
            }
        }
        if(ok){
            // vir_chessが答え
            //cout << "答えが見つかりました" << endl;
            break;
        }
    }while(next_permutation(pos.begin(),pos.end()));
    
    vector<vector<char>> board(8,vector<char>(8,'.'));
    for(auto [x,y] : vir_chess){
        board[x][y] = 'Q';
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}