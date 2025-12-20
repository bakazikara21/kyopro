#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(N+1);
    for(int i = 0; i < N; i++){
        int x,y;
        cin >> x >> y;
        // A_{i+1}はA_{x}の末尾にyを加えた
        A[i+1].push_back(-x);
        A[i+1].push_back(y);
    }
    vector<pair<vector<int>,int>> vec(N);
    for(int i = 0; i < N; i++){
        vec[i] = {A[i+1],i+1};
    }
    sort(vec.begin(),vec.end());
    for(int i = 0; i < N; i++){
        for(auto v : vec[i].first){
            cout << v << " ,";
        }
        cout << " i+1 = " << vec[i].second << endl;
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        int num = vec[i].first.at(0);
        if(num < 0) cnt++;
    }
}