#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> T(N);
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        T[i] = {t,i+1};
    }
    sort(T.begin(),T.end());
    for(int i = 0; i < 3; i++){
        cout << T[i].second << " ";
    }
    cout << endl;
}