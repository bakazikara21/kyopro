#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<bool> used(N,false);
    // 下から行くとき
    int id = 1;
    int cnt1 = 0;
    for(int i = 0; i < N; i++){
        if(used[i] == true) continue;

        ll a = A[i];
        while(id < N and (used[id]==true or 2*a > A[id])){
            id++;
        }
        if(id < N and 2*a <= A[id]){
            cnt1++;
            used[i] = true;
            used[id] = true;
        }
        if(id >= N) break;
    }
    for(int i = 0; i < N; i++) used[i] = false;

    // 上から行くとき
    id = N-2;
    int cnt2 = 0;
    for(int i = N-1; i >= 0; i--){
        if(used[i] == true) continue;

        ll a = A[i];
        while(id >= 0 and (used[id]==true or 2*A[id] > a)){
            id--;
        }
        if(id >= 0 and 2*A[id] <= a){
            cnt2++;
            used[i] = true;
            used[id] = true;
        }
        if(id < 0) break;
    }
    cout << max(cnt1,cnt2) << endl;
}
/*
6
3 10 20 26 39 56

*/