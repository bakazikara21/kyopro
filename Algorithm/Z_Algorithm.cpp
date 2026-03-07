#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

/*
    長さNの文字列Sに対するz_algorithm:
    Z[i] := S[0:(N-i)]とS[i:N]の最長共通部分文字列の長さ
    となる配列ZをO(N)で生成するアルゴリズム
*/
vector<int> z_algorithm(string S){
    int N = (int)S.size();
    vector<int> Z(N);   Z[0] = N;

    int L = 0,R = 0;    // Z[0:(R-L+1)] = Z[L:R+1]かつRが最大となるL,Rを更新していく
    for(int i = 1; i < N; i++){
        if(i <= R){
            int k = i-L;    // iはL以上は確定しているので
            Z[i] = min(Z[k],R-i+1);
        }
    
        // L,Rを更新する
        while(i+Z[i] < N and S[Z[i]] == S[i+Z[i]]){
            Z[i]++; // Rを伸ばす
        }

        if(i+Z[i]-1 > R){
            L = i;
            R = i+Z[i]-1;
        }
    }
    return Z;
}