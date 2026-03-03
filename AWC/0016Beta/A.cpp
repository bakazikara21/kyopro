#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ll sum = 0;
    int N; cin >> N;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        ll A,B; cin >> A >> B;
        if(A > B){
            cnt++;
            sum += (A-B);
        }
    }
    cout << cnt << " " << sum << endl;
}
