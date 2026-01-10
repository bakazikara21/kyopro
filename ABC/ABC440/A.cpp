#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int X,Y;
    cin >> X >> Y;
    while(Y > 0){
        X *= 2;
        Y--;
    }
    cout << X << endl;
}