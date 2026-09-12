#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;

    ll ans = 1;
    for(ll i = 1; i*i*i <= N; i++){
        // i*i*iは回文なのか?
        bool ok = true;
        string T = to_string(i*i*i);

        int siz = (int)T.size();
        for(int j = 0; j < siz/2; j++){
            if(T[j] != T[siz-1-j]){
                ok = false;
                break;
            }
        }
        if(ok){
            ans = max(ans,i*i*i);
        }
    }
    cout << ans << endl;
}
