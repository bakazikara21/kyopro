#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int H,W,N;
    cin >> H >> W >> N;
    vector<vector<int>> A(H,vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
        }
    }
    set<int> se;
    for(int i = 0; i < N; i++){
        int B;
        cin >> B;
        se.insert(B);
    }
    int ans = 0;
    for(int i = 0; i < H; i++){
        int num = 0;
        for(int j = 0; j < W; j++){
            if(se.count(A[i][j])){
                num++;
            }
        }
        ans = max(ans,num);
    }
    cout << ans << endl;
}