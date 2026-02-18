#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e15;
const int inf = (int)1e9;

int main(){
    int N,K;
    cin >> N >> K;
    vector<ll> A(N),presum(N+1);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        presum[i+1] = presum[i]+A[i];
    }
    // ans <= presum[N]/K;
    ll average = presum[N]/K;   // これを超えたらこれ以上トラックに載せる意味がない
    
    if(K == 1){
        cout << presum[N] << endl;
        return 0;
    }
    /*
        最小値を最大化-> 答えで二分探索
        最小値をX以上にできるか-> Yesなら ans >= X
    */
    ll left = 0, right = (presum[N]/K)+1;
    ll x = (right+left)/2;
    while((right-left) > 1){
        int div = 0;
        for(int i = 0; i < N; i++){
            ll sum = 0;
            while(i < N and sum < x){
                sum += A[i];
                i++;
            }
            if(sum >= x) div++,i--; // 分割数をインクリメント
        }
        if(div >= K){
            // xはもっと大きくできる
            left = x;
        }
        else right = x;
        x = (right+left)/2;
    }
    cout << left << endl;
}
