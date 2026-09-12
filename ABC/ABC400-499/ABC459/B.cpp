#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<string> S(N);
    vector<int> C(N);
    for(int i = 0; i < N; i++){
        cin >> S[i];
        C[i] = (S[i][0]-'a' + 6);
        if(C[i] == 24 or C[i] == 30 or C[i] == 27) C[i]--;
        else if(C[i] == 31) C[i] -= 2;
        C[i] /= 3;
    }
    for(int i = 0; i < N; i++) cout << C[i];
    cout << endl;
}
