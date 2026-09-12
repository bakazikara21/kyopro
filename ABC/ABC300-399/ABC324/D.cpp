#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string S;
    cin >> N >> S;
    
    vector<int> cnt(10);
    for(int i = 0; i < N; i++){
        cnt[S[i]-'0']++;
    }
    ll ans = 0;
    for(ll i = 0; i*i < (ll)1e13; i++){
        bool ok = true;
        string T = "";
        T += to_string(i*i);
        while(T.size() < N){
            T = '0'+T;
        }
        if((int)T.size() > N){
            break;
        }
        vector<int> cnt2(10);
        for(int j = 0; j < N; j++){
            cnt2[T[j]-'0']++;
        }
        for(int i = 0; i < 10; i++){
            if(cnt[i] != cnt2[i]){
                ok = false;
                break;
            }
        }
        if(ok) ans++;
    }
    cout << ans << endl;
}
