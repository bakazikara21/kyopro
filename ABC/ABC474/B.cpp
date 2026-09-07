#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<vector<int>> group(N/10 + 1);
    for(int i = 0; i < N; i++){
        int P; cin >> P;
        group[i/10].push_back(P);
    }
    bool ok = true;
    for(int i = 0; i < (N/10 + 1); i++){
        sort(group[i].begin(),group[i].end());
        int M = (int)group[i].size();
        for(int j = 0; j < M; j++){
            // i*10 + 1 ~ i*10 + 10
            if(group[i][j] != i*10 + j+1){
                ok = false;
                break;
            }
        }
    }
    if(ok){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}
