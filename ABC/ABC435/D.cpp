#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    for(int i = 0; i < M; i++){
        int X,Y;
        cin >> X >> Y;
        X--; Y--;

        graph[Y].push_back(X);
    }
    vector<bool> reachable(N,false);    // 白色ならfalse
    int Q;
    cin >> Q;
    queue<int> que;
    for(int q = 0; q < Q; q++){
        int num,v;
        cin >> num >> v;
        v--;
        if(num == 1){
            // 頂点vを黒色にする
            // 頂点vに到達できるやつを全員黒色にする
            if(reachable[v] == true) continue;
            reachable[v] = true;

            que.push(v);
            // 黒色の頂点を見つけたらpushしない
            while(!que.empty()){
                int nv = que.front(); que.pop();
                for(int nextv : graph[nv]){
                    if(reachable[nextv] == true) continue;

                    reachable[nextv] = true;
                    que.push(nextv);
                }
            }
        }
        if(num == 2){
            // 自分は黒色か?
            if(reachable[v] == true){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}
