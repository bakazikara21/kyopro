#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
int main(){
    int N;
    cin >> N;
    int num = N % 10;
    N /= 10;
    bool ok = true;
    while(N > 0){
        if(num != (N%10)){
            ok = false;
            break; 
        }
        N /= 10;
    }
    if(ok){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}
