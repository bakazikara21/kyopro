#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;
    // N個の単語をM行で表示するときの横幅の最小値
    vector<ll> L(N);
    for(int i = 0; i < N; i++){
        cin >> L[i];
    }
    ll left = 0;  // 最小候補
    ll right = (ll)5e15;
    ll mid = (right+left)/2;
    while((right-left) > 1){
        ll len = 0;
        int m = 1;
        for(int i = 0; i < N; i++){
            if(L[i] > mid){
                m = M+1;
                break;
            }
            if(len == 0){
                len += L[i];
            }
            else if(len + 1 + L[i] <= mid){
                len += L[i]+1;
            }
            else {
                m++;
                len = L[i];
            }
        }
        if(m > M){
            // もっと幅広く
            left = mid;
        }else{
            right = mid;
        }
        mid = (right+left)/2;
    }
    cout << right << endl;
}
/*
https://atcoder.jp/contests/abc319/tasks/abc319_d
*/