#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,A,B;
    cin >> N >> A >> B;
    // 二次元imos * 2
    vector<vector<int>> imosA(N+2,vector<int>(N+2,0));
    vector<vector<int>> imosB(N+2,vector<int>(N+2,0));
    for(int i = 0; i < A; i++){
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        imosA[r2+1][c2+1]++;
        imosA[r1][c1]++;
        imosA[r1][c2+1]--;
        imosA[r2+1][c1]--;
    }
    for(int i = 0; i < B; i++){
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        imosB[r2+1][c2+1]++;
        imosB[r1][c1]++;
        imosB[r1][c2+1]--;
        imosB[r2+1][c1]--;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j < N; j++){
            imosA[i][j+1] += imosA[i][j];
            imosB[i][j+1] += imosB[i][j];
        }
    }
    for(int j = 1; j <= N; j++){
        for(int i = 1; i < N; i++){
            imosA[i+1][j] += imosA[i][j];
            imosB[i+1][j] += imosB[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(imosA[i][j]>=1 and imosB[i][j]>=1) ans++;
        }
    }
    cout << ans << endl;
}
