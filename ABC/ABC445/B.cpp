#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N;
    cin >> N;
    int m = 0;
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S[i];
        m = max(m,(int)S[i].size());
    }
    for(int i = 0; i < N; i++){
        int k = (m-(int)S[i].size())/2;
        for(int i = 0; i < k; i++){
            cout << ".";
        }
        cout << S[i];
        for(int i = 0; i < k; i++){
            cout << ".";
        }
        cout << endl;
    }
}
