#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    for(int i = 0; i < N-1; i++){
        if(S[i] == 'a' and S[i+1] == 'b'){
            cout << "Yes" << endl;
            return 0;
        }
        if(S[i] == 'b' and S[i+1] == 'a'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
