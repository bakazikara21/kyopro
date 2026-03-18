#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
    LSD基数ソート (非負整数専用)
    低い桁から順に、桁の値(0~9)でソートする
*/
void radixSort(vector<ll> &A){
    // 1. 配列内の最大値を見つける
    ll max_val = 0LL;
    for(ll a : A){
        max_val = max(max_val, a);
    }

    ll ten = 1;
    // 2. 最大値の桁が尽きるまでループ
    while(max_val / ten > 0){
        vector<vector<ll>> bucket(10);
        
        for(ll a : A){
            int id = (a / ten) % 10;
            bucket[id].push_back(a);
        }
        
        int j = 0;
        for(int i = 0; i < 10; i++){
            for(ll a : bucket[i]){
                A[j] = a;
                j++;
            }
        }
        ten *= 10;
    }
}