#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;

int main(){
    int N;
    cin >> N;
    
    string S;
    cin >> S;   // 0,1からなる文字列

    vector<ll> C(N);
    for(int i = 0; i < N; i++){
        cin >> C[i];    // S[i]をビット反転させるのに必要なコスト
    }
    // いい文字列は 01010101... or 10101010... のときのi文字目から左右対称
    // N*2通りしかない
    vector<ll> dpzo(N+1),dpoz(N+1); // 先頭からiビット目までを010101...にするコストと101010...にするコスト
    for(int i = 0; i < N; i++){
        dpoz[i+1] = dpoz[i];
        dpzo[i+1] = dpzo[i];
        if(i % 2 == 0){
            if(S[i] == '0'){
                dpoz[i+1] += C[i];
            }
            else dpzo[i+1] += C[i];
        }
        if(i % 2 == 1){
            if(S[i] == '1'){
                dpoz[i+1] += C[i];
            }
            else dpzo[i+1] += C[i];
        }
    }
    ll ans = INF;
    for(int i = 0; i < N-1; i++){
        // iビット目まで1010...でi+1ビット目から010101が始まる
        ans = min(ans,dpoz[i+1]+dpzo[N]-dpzo[i+1]);
        ans = min(ans,dpzo[i+1]+dpoz[N]-dpoz[i+1]);
    }
    cout << ans << endl;
}
