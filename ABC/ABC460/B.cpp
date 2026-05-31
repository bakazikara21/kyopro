#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        ll X1,Y1,R1,X2,Y2,R2;
        cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;
        ll distC = (X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2);
        if(distC <= (R1+R2)*(R1+R2) and distC >= (R1-R2)*(R1-R2)){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}
