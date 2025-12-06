#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<ll> leng(101);
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        leng[A]++;
    }
    ll ans = 0;
    for(int i = 1; i <= 100; i++){
        if(leng[i] < 3) continue;
        ans += leng[i]*(leng[i]-1)*(leng[i]-2)/6;
    }
    cout << ans << endl;
}
