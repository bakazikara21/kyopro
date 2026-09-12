#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int H = 2000;
    int W = 2000;
    vector<vector<int>> X(H,vector<int>(W));
    
    int N;
    cin >> N;
    vector<int> U(N),D(N),L(N),R(N);
    for(int i = 0; i < N; i++){
        cin >> U[i] >> D[i] >> L[i] >> R[i];
        U[i]--; L[i]--; D[i]--; R[i]--;
    
        X[U[i]][L[i]] += 1;
        if(R[i]+1 < W) X[U[i]][R[i]+1] -= 1;
        if(D[i]+1 < W) X[D[i]+1][L[i]] -= 1;
        if(D[i]+1 < W and R[i]+1 < W) X[D[i]+1][R[i]+1] += 1;
    }
    for(int i = 0; i < H; i++){
        for(int j = 1; j < W; j++){
            X[i][j] += X[i][j-1];
        }
    }
    for(int j = 0; j < H; j++){
        for(int i = 1; i < W; i++){
            X[i][j] += X[i-1][j];
        }
    }
    ll sum = 0;
    vector<vector<int>> cnt(H,vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(X[i][j] <= 0){
                sum++;
            }
            if(X[i][j] == 1){
                cnt[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 1; j < W; j++){
            cnt[i][j] += cnt[i][j-1];
        }
    }
    for(int j = 0; j < H; j++){
        for(int i = 1; i < W; i++){
            cnt[i][j] += cnt[i-1][j];
        }
    }
    for(int k = 0; k < N; k++){
        int one = cnt[D[k]][R[k]];
        if(U[k]-1 >= 0) one -= cnt[U[k]-1][R[k]];
        if(L[k]-1 >= 0) one -= cnt[D[k]][L[k]-1];
        if(U[k]-1 >= 0 and L[k]-1 >= 0) one += cnt[U[k]-1][L[k]-1];
        cout << sum + one << endl;
    }
    //cout << sum << endl;
    /*
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            cout << X[i][j] << " ";
        }
        cout << endl;
    }
    */ 
}