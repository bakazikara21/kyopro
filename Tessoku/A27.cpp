#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int A,B;
    cin >> A >> B;

    if(A < B) swap(A,B);

    int r = A % B;
    while(r != 0){
        A = B;
        B = r;
        r = A % B;
    } 
    cout << B << endl;
}
