#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)10007; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,L,K; cin >> N >> L >> K;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    ll sum = 0;
    int last = L-A[N-1];
    for(int i = 0; i < N; i++){
        if(i > 0) A[i] -= sum;
        sum += A[i];
    }
    int left = 0, right = L;
    int x = (right+left)/2;
    while((right-left)>1){
        // スコアをxにすることができるか
        sum = 0;
        int cnt = 0;
        for(int i = 0; i < N; i++){
            sum += A[i];
            if(sum >= x){
                sum = 0;
                cnt++;
            } 
            if(i == N-1){
                sum += last;
                if(sum >= x){
                    sum = 0;
                    cnt++;
                } 
            }
        }
        if(cnt >= K+1){
            // できる
            left = x;
        }
        else right = x;
        x = (right+left)/2;
    }
    cout << left << endl;
}
