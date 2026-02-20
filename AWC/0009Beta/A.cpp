#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int K,M;
    cin >> K >> M;
    int sum = 0;
    for(int i = 0; i < K; i++){
        int L;
        cin >> L;
        sum += L;
    }
    cout << (sum % M) << endl;
}
