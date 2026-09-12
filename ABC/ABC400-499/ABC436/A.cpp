#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string S;
    cin >> N >> S;

    while((int)S.size() != N){
        S = 'o'+S;
    }
    cout << S << endl;
}