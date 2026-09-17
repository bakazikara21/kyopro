#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; string S; cin >> N >> S;

    vector<bool> skip(N,false);
    stack<pair<int,int>> sta;
    vector<int> imos(N+1);
    for(int i = 0; i < N; i++){
        if(S[i] != '(' and S[i] != ')') continue;
        if(S[i] == '('){
            sta.push({1,i});
        }
        else if(!sta.empty()){
            pair<int,int> top = sta.top(); sta.pop();
            int l = top.second;
            int r = i;
            imos[l]++;
            imos[r+1]--;
        }
    }
    for(int i = 0; i < N; i++){
        imos[i+1] += imos[i];
        if(imos[i] > 0) continue;
        cout << S[i];
    }
    cout << endl;
}
