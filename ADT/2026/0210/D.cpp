#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    string S,T;
    cin >> S >> T;
    int sizS = (int)S.size();
    int sizT = (int)T.size();

    vector<int> ans;
    int now = 0;
    for(int i = 0; i < sizT; i++){
        if(T[i] == S[now]){
            ans.push_back(i+1);
            now++;
        }
        if(now == sizS) break;
    }
    for(int a : ans){
        cout << a << " ";
    }
    cout << endl;
}
