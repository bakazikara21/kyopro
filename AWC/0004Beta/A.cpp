#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,S,T;
    cin >> N >> S >> T;
    int sum = 0;
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        sum += A;
        if((T-S)*60 < sum){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
