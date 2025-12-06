#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool ok = false;
    for(int i = 0; i < N-2; i++){
        if(S[i] == S[i+1] and S[i+1] == S[i+2]){
            ok = true;
            break;
        }
    }
    if(ok){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
