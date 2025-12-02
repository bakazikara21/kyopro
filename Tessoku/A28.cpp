#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    ll num = 0;
    for(int i = 0; i < N; i++){
        char T;
        ll A;
        cin >> T >> A;
        
        if(T == '+'){
            num += A;
        }
        if(T == '-'){
            num -= A;
        }
        if(T == '*'){
            num *= A;
        }
        num += 10000;
        num %= 10000;
        cout << num << endl;
    }
}
