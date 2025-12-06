#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    ll L;
    cin >> N >> L;

    ll ans = 0;
    for(int i = 0; i < N; i++){
        ll A;
        char B;
        cin >> A >> B;
        if(B == 'E'){
            ans = max(ans,L-A);
        }else{
            ans = max(ans,A);
        }
    }
    cout << ans << endl;
}
