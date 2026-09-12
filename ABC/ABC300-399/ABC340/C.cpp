#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    // N*log2(N)
    ll M = 0;
    ll two = 1;
    while(two < N){
        two *= 2;
        M++;
    }
    cout << N*M-(two-N) << endl;
    /*
    cout << "N = " << N << endl;
    cout << "M = " << M << endl;
    cout << "two = " << two << endl;
    */
}
