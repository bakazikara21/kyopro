#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    set<string> st;
    for(int i = 0; i < N; i++){
        string S;
        cin >> S;
        if(!st.count(S)){
            st.insert(S);
            cout << i+1 << endl;
        }
    }
}