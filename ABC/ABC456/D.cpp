#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;
int main(){
    string S; cin >> S;
    int N = (int)S.size();

    ll ans = 0;
    vector<ll> cnt(N);  // cnt[i] := S[i]が左端のときの場合の数
    ll sumA = 0, sumB = 0, sumC = 0;
    for(int r = 0; r < N; r++){
        // 他の文字で終わるときの累積和+1
        if(r == 0){
            if(S[r] == 'a') sumA++;
            if(S[r] == 'b') sumB++;
            if(S[r] == 'c') sumC++;
            cnt[0] = 1;
        }
        else {
            if(S[r] == 'a'){
                cnt[r] = sumB+sumC+1;
                cnt[r] %= mod;
                sumA += cnt[r];
            }
            if(S[r] == 'b'){
                cnt[r] = sumA+sumC+1;
                cnt[r] %= mod;
                sumB += cnt[r];
            }
            if(S[r] == 'c'){
                cnt[r] = sumA+sumB+1;
                cnt[r] %= mod;
                sumC += cnt[r];
            }
        }
        sumA %= mod;
        sumB %= mod;
        sumC %= mod;
        ans += cnt[r];
        ans %= mod;
    }
    cout << ans << endl;
}
