#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    string S,T; cin >> S >> T;
    string s = "", t = "";
    int N = (int)S.size();
    int M = (int)T.size();
    for(int i = 0; i < N; i++){
        if(S[i] == 'A') continue;
        s += S[i];
    }
    for(int i = 0; i < M; i++){
        if(T[i] == 'A') continue;
        t += T[i];
    }
    if(s != t){
        cout << -1 << endl;
        return 0;
    }
    int now = 0;
    ll ans = 0;
    for(int i = 0; i < N; i++){
        if(now < M and S[i] == 'A' and T[now] != 'A'){
            ans++;
        }
        else if(now < M and S[i] != 'A' and T[now] == 'A'){
            i--;
            now++;
            ans++;
        }
        else if(now < M and S[i] == T[now]){
            now++;
        }
        else if(now == M and S[i] == 'A'){
            ans++;
        }
    }
    ans += M-(now);
    cout << ans << endl;
}
