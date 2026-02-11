#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N;
    cin >> N;
    char left,right;
    int ans = 0;
    for(int i = 0; i < N; i++){
        char L,R;
        cin >> L >> R;
        if(i == 0){
            left = L;
            right = R;
        }
        else {
            left = L;
            if(left == right){
                ans++;
            }
        }
        right = R;
    }
    cout << ans << endl;
}
