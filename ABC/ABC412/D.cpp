#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

/*
    頂点数Nのサイクル1つ or
    頂点数N-3のサイクル　と　頂点数3のサイクル　の2つ or
    頂点数N-4のサイクル　と　頂点数4のサイクル　の2つ　の3種類に限られる
*/
int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    for(int i = 0; i < M; i++){
        int u,v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = inf;
    vector<int> pos(N);
    for(int i = 0; i < N; i++) pos[i] = i;
    do
    {
        /* 頂点数Nのサイクルにするとき */
        int cnt = 2*N;    // 必要な操作回数
        for(int i = 0; i < N; i++){
            if(i == 0){
                // 頂点pos[0]はpos[N-1]とpos[1]とつながっているべき
                for(int to : graph[pos[i]]){
                    if(to == pos[1] or to == pos[N-1]) cnt--;
                    else cnt++;
                }
                continue;
            }
            // 頂点pos[i]はpos[i-1]とpos[i+1 % N]とつながっているべき
            for(int to : graph[pos[i]]){
                if(to == pos[i-1] or to == pos[(i+1)%N]) cnt--;
                else cnt++;
            }
        }
        cnt /= 2;   // ダブりを解消する
        ans = min(ans,cnt);
    } while (next_permutation(pos.begin(),pos.end()));
    //cout << "cycleN = " << ans << endl;
    /*
        頂点数N-3のサイクル　と　頂点数3のサイクルの2つにわけるとき
    */
    if(N < 6){
        cout << ans << endl;
        return 0;
    }
    for(int i = 0; i < N; i++) pos[i] = i;
    do
    {
        int cnt1 = 6, cnt2 = 2*(N-3);    // 必要な操作回数
        /* 頂点数3のサイクルにするとき */
        for(int i = 0; i < 3; i++){
            if(i == 0){
                // 頂点pos[0]はpos[2]とpos[1]とつながっているべき
                for(int to : graph[pos[i]]){
                    if(to == pos[1] or to == pos[2]) cnt1--;
                    else cnt1++;
                }
                continue;
            }
            // 頂点pos[i]はpos[i-1]とpos[i+1 % N]とつながっているべき
            for(int to : graph[pos[i]]){
                if(to == pos[i-1] or to == pos[(i+1)%3]) cnt1--;
                else cnt1++;
            }
        }

        /* 頂点数N-3のサイクルにするとき */
        for(int i = 3; i < N; i++){
            if(i == 3){
                // 頂点pos[3]はpos[N-1]とpos[4]とつながっているべき
                for(int to : graph[pos[i]]){
                    if(to == pos[4] or to == pos[N-1]) cnt2--;
                    else cnt2++;
                }
                continue;
            }
            // 頂点pos[i]はpos[i-1]とpos[i+1 % N]とつながっているべき
            for(int to : graph[pos[i]]){
                // i+1 >= N i+1 - (N-3)
                int id = (i+1)%N;
                if(i+1 >= N) id = i+1 - (N-3);
                if(to == pos[i-1] or to == pos[id]) cnt2--;
                else cnt2++;
            }
        }
        // ダブりを解消する
        ans = min(ans,(cnt1+cnt2)/2);
    } while (next_permutation(pos.begin(),pos.end()));
    //cout << "cycleN-3 = " << ans << endl;
    if(N < 8){
        cout << ans << endl;
        return 0;
    }

    for(int i = 0; i < N; i++) pos[i] = i;
    do
    {
        int cnt1 = 8, cnt2 = 8;    // 必要な操作回数
        /* 頂点数4のサイクルにするとき */
        for(int i = 0; i < 4; i++){
            if(i == 0){
                // 頂点pos[0]はpos[3]とpos[1]とつながっているべき
                for(int to : graph[pos[i]]){
                    if(to == pos[1] or to == pos[3]) cnt1--;
                    else cnt1++;
                }
                continue;
            }
            // 頂点pos[i]はpos[i-1]とpos[i+1 % N]とつながっているべき
            for(int to : graph[pos[i]]){
                if(to == pos[i-1] or to == pos[(i+1)%4]) cnt1--;
                else cnt1++;
            }
        }
        
        /* 頂点数N-4のサイクルにするとき */
        for(int i = 4; i < N; i++){
            if(i == 4){
                // 頂点pos[4]はpos[N-1]とpos[5]とつながっているべき
                for(int to : graph[pos[i]]){
                    if(to == pos[5] or to == pos[N-1]) cnt2--;
                    else cnt2++;
                }
                continue;
            }
            // 頂点pos[i]はpos[i-1]とpos[i+1 % N]とつながっているべき
            for(int to : graph[pos[i]]){
                int id = (i+1)%N;
                if(i+1 >= N) id = i+1 - (N-4);
                if(to == pos[i-1] or to == pos[id]) cnt2--;
                else cnt2++;
            }
        }
        
        ans = min(ans,(cnt1+cnt2)/2);
    } while (next_permutation(pos.begin(),pos.end()));
    //cout << "cycleN-4 = " << ans << endl;
    cout << ans << endl;
}