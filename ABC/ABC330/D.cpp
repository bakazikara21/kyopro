#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }
    vector<vector<int>> row(N),column(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(S[i][j] == 'o'){
                row[i].push_back(j);
            }
        }
    }
    for(int j = 0; j < N; j++){
        for(int i = 0; i < N; i++){
            if(S[i][j] == 'o'){
                column[j].push_back(i);
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i < N; i++){
        ll combi = ((ll)row[i].size()-1)*((ll)row[i].size()-2)/2;
        for(int j : row[i]){
            ll combj = ((ll)column[j].size()-1)*((ll)column[j].size()-2)/2;
            ans += combi*combj;
        }
    }
    cout << ans << endl;
}
