#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N;
    ll S;
    cin >> N >> S;
    int pls = 0;
    if(N%2 == 1) pls++;
    vector<ll> A(N),B(N/2),C(N/2 + pls);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(i < N/2){
            B[i] = A[i];
        }
        else C[i-N/2] = A[i];
    }
    /*
        半分全列挙
    */
    int bmax = 1<<(N/2);
    int cmax = 1<<(N/2 + pls);
    map<ll,int> cntb,cntc;
    for(int b = 0; b < bmax; b++){
        ll sum = 0;
        for(int bit = 0; bit < N/2; bit++){
            if((b >> bit)&1){
                sum += B[bit];
            }
        }
        cntb[sum]++;
    }
    for(int c = 0; c < cmax; c++){
        ll sum = 0;
        for(int bit = 0; bit < N/2 + pls; bit++){
            if((c >> bit)&1){
                sum += C[bit];
            }
        }
        cntc[sum]++;
    }
    ll ans = 0;
    for(auto [key,val] : cntb){
        ll object = S-key;
        auto itr = cntc.lower_bound(object);
        if(itr == cntc.end()) continue;
        if(itr->first+key == S){
            ans += (ll)val*(itr->second);
        }
    }
    if(S == 0){
        cout << 1 << endl;
    }
    else cout << ans << endl;
}