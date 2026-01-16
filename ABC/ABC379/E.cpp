#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    double ans = 0.0;
    for(int i = 1; i <= 99; i++){
        ans += 1.0*i/(i+1);
    }
    cout << "My answer is = " << 100.0*ans/99.0 / 101.0 << endl;
}
