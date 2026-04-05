#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int M,D; cin >> M >> D;
    if(M == 1 and D == 7){
        cout << "Yes" << endl;
        return 0;
    }
    if(M == 3 and D == 3){
        cout << "Yes" << endl;
        return 0;
    }
    if(M == 5 and D == 5){
        cout << "Yes" << endl;
        return 0;
    }
    if(M == 7 and D == 7){
        cout << "Yes" << endl;
        return 0;
    }
    if(M == 9 and D == 9){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
