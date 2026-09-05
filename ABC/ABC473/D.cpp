#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

// とりあえず、全探索しか思いつかなかった。
// dfsは解の個数を無駄なく全探索できている
int main(){
    int N,K; cin >> N >> K;
    if(N == 1){
        cout << K << endl;
        return 0;
    }
    vector<int> A(N);
    
    vector<vector<int>> aryA;
    auto dfs = [&](auto self,int id, int k)->void{
        // A[id]まで定まっているとき、
        // A[0]+A[1]+...+A[id-1] = kのとき
        if(id == 1){
            // A[0] = k
            A[0] = k;
            aryA.push_back(A);
            return;
        }
        int imax = k/id;
        for(int i = imax; i >= 0; i--){
            A[id-1] = i;
            self(self,id-1,k-i*id);
        }
        return;
    };
    for(int i = K/N; i >= 0; i--){
        A[N-1] = i;
        dfs(dfs,N-1,K-A[N-1]*N);
    }
    sort(aryA.begin(),aryA.end());
    int M = (int)aryA.size();
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cout << aryA[i][j] << " ";
        }
        cout << endl;
    }
}
