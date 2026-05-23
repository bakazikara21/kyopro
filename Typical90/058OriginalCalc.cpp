#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 100000;

int bitsum(int x){
    int sum = 0;
    while(x > 0){
        sum += x%10;
        x /= 10;
    }
    return sum;
}
int main(){
    int N; cin >> N;
    ll K; cin >> K;

    // 現在、Nが表示されている。
    vector<int> visited(100000,-1);    // 整数をグループ分け
    int j = N;                  // Nスタートでサイクルが見つかるまで探索
    int now = 0;
    visited[j] = now;
    j += bitsum(j); j %= mod;
    int cycle = 1;
    while(visited[j] == -1){
        now++;
        visited[j] = now;
        j += bitsum(j); j %= mod;
        if(visited[j] != -1){
            // 次の頂点jに行ったことがあるならば
            cycle = now - visited[j] + 1;
            break;
        }
    }
    if(K < visited[j]){
        j = N;
        for(int k = 0; k < K; k++){
            j += bitsum(j); j %= mod;
        }
        cout << j << endl;
        return 0;
    }
    K -= visited[j];
    K %= cycle;
    // 頂点j をスタートしてcycleを辿るだけ
    for(int k = 0; k < K; k++){
        j += bitsum(j); j %= mod;
    }
    cout << j << endl;
}