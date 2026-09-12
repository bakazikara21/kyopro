#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; string T; cin >> N >> T;
    /*
        文字の長さが偶数かつpopcount = 偶数 or
        文字の長さが奇数かつpopcount = 奇数
    */
    ll ans = 0;
    for(int i = 0; i < N; i++){
        // 1文字のとき
        if(T[i] == '1') ans++;
    }
    ll cnt = 0;
    // i = 0を左端とするときの部分文字列の個数を数える
    bool ok = (T[0]=='1');
    for(int i = 1; i < N; i++){
        if(ok and T[i] == '1') cnt++;
        else if(ok == false and T[i] == '0'){
            cnt++;
            ok = true;
        }
        else ok = false;
    }
    //cout << "cnt = " << cnt << endl;
    ans += cnt;
    for(int i = 1; i < N; i++){
        // iを左端とするときの部分文字列の個数を高速に数える
        if(T[i] == T[i-1] and T[i]=='1'){
            cnt--;
            ans += cnt;
        }
        else if(T[i] == T[i-1] and T[i]=='0'){
            cnt--;
            cnt = (N-1-i)-cnt;
            ans += cnt;
        }
        else if(T[i] == '0' and T[i-1] == '1'){
            ans += cnt;
        }
        else {
            cnt = (N-1-i)-cnt;
            ans += cnt;
        }
    }
    cout << ans << endl;
}
