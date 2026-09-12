#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    string S,T; cin >> S >> T;
    ll N = (ll)S.size();
    ll M = (ll)T.size();
    // Tを部分列として含むSの部分文字列の個数cntを求める。
    ll ans = 0;
    int dx = -1;
    vector<int> cnt(M,-1);
    for(int i = 0; i < N; i++){
        // SのなかでTの部分列を探せばよさそう
        // i文字目までで何個の部分文字列が
        // Tを部分列として持つのか
        /*
            i文字目まででT[0]~T[M-1]が出現している前提で、
            T[0]が出現する最大の添え字をdxとすると
            ans += dx+1;
            ただし、dxはT[0]~T[M-1]が部分列として出現している最大の添え字とする。
        */
        for(int j = M-1; j >= 0; j--){
            if(T[j] == S[i]){
                if(j == 0 and M == 1){
                    dx = i;
                    continue;
                }
                if(j == 0){
                    cnt[j] = i;
                }
                else if(j == M-1 and cnt[j-1] >= 0){
                    dx = cnt[j-1];
                    cnt[j-1] = -1;
                }
                else if(cnt[j-1] >= 0){
                    cnt[j] = cnt[j-1];
                    cnt[j-1] = -1;
                }
            }
        }
        ans += dx+1;
    }
    cout << N*(N+1)/2 - ans << endl;
}
