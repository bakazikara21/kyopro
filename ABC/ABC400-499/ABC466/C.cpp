#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; 
    cin >> N;
    int l = 1, r = 2;
    string S;
    ll ans = 0;
    while(true){
        cout << "? " << l << " " << r << endl;
        cin >> S;
        if(S == "Yes" and r <= N){
            r++;
        }
        else{
            ans += (r-l-1);
            l++;
        }
        r = max(l+1,r);
        while(r == N+1 and l < N){
            ans += (r-l-1);
            l++;
        }
        if(l == N) break;
    }
    cout << "! " << ans << endl;
    return 0;
}
