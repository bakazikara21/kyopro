#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<int> A(N),B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];
    int M; cin >> M;
    vector<string> S(M);
    vector<vector<vector<bool>>> exist(11,vector<vector<bool>>(10,vector<bool>(26,false)));
    for(int j = 0; j < M; j++){
        cin >> S[j];
        int sz = (int)S[j].size();
        for(int i = 0; i < sz; i++){
            exist[sz][i][S[j][i]-'a'] = true;
        }
    }
    for(int j = 0; j < M; j++){
        string T = S[j];
        int sz = (int)T.size();
        if(sz != N){
            cout << "No" << endl;
            continue;
        }
        bool ok = true;
        for(int i = 0; i < sz; i++){
            if(!exist[A[i]][B[i]-1][T[i]-'a']){
                ok = false;
                break;
            }
        }
        if(ok)  cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
