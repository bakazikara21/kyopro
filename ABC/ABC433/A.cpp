#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int x,y,z;
    cin >> x >> y >> z;
    for(int i = 0; i < 200; i++){
        int X = x + i;
        int Y = y + i;
        if(X == Y*z){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}

