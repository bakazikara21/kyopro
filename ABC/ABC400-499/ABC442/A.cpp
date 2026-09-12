#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S;
    cin >> S;
    int cnt = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'i' or S[i] == 'j'){
            cnt++;
        }
    }
    cout << cnt << endl;
}
