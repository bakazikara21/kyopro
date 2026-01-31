#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = (int)1e8;
int main(){
    int T;
    cin >> T;

    vector<int> di = {-1,-1,-1};
    vector<int> dj = {1,0,-1};
    for(int t = 0; t < T; t++){
        int N,C;
        cin >> N >> C;
        vector<string> S(N);
        for(int i = 0; i < N; i++){
            cin >> S[i];
        }
        int si = N-1; 
        int sj = C-1;
        vector<int> minimum(N);
        for(int i = 0; i < N; i++){
            // 下から探索してi列目の何行目まで空きマスなのか
            int maxi = N;
            while(maxi-1 >= 0 and S[maxi-1][i] == '.'){
                maxi--;
            }
            minimum[i] = maxi;
        }
        vector<vector<bool>> used(N,vector<bool>(N,false));
        queue<pair<int,int>> que;
        que.push({si,sj});
        while(!que.empty()){
            auto [i,j] = que.front(); que.pop();
            if(used[i][j] == true) continue;
            used[i][j] = true;
            for(int k = 0; k < 3; k++){
                int ni = i+di[k];
                int nj = j+dj[k];
                if(ni < 0 or ni >= N or nj < 0 or nj >= N) continue;
                if(S[ni][nj] == '#'){
                    if(minimum[nj] != ni+1) continue;
                    minimum[nj]--;
                    S[ni][nj] = '.';    // 破壊可能
                }
                // (ni,nj)に行けたなら
                if(minimum[nj] == ni+1) minimum[nj]--;
                que.push({ni,nj});
            }
        }
        for(int j = 0; j < N; j++){
            if(used[0][j]){
                cout << '1';
            }
            else cout << '0';
        }
        cout << endl;
        /*
        for(int i = 0; i < N; i++){
         for(int j = 0; j < N; j++){
             cout << used[i][j] << " ";
         }
         cout << endl;
        }
        */
    }
}
