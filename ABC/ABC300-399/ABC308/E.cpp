#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &a : A) cin >> a;
    string S; cin >> S;
    vector<vector<vector<ll>>> mex(3,vector<vector<ll>>(3,vector<ll>(3)));
    vector<int> used(4);
    map<tuple<int,int,int>,ll> mp;
    for(int i = 0; i < 3; i++){
        used[i]++;
        for(int j = 0; j < 3; j++){
            used[j]++;
            for(int k = 0; k < 3; k++){
                used[k]++;
                for(int t = 0; t < 4; t++){
                    if(used[t] == 0){
                        mex[i][j][k] = t;
                        mp[{i,j,k}] = 0;
                        // cout << "mex(" << i << ", " << j << ", " << k <<  ")" << " = " << t << endl;
                        break;
                    }
                }
                used[k]--;
            }
            used[j]--;
        }
        used[i]--;
    }
    vector<vector<ll>> cntM(N,vector<ll>(3)),cntX(N,vector<ll>(3));
    for(int i = 0; i < N; i++){
        int n = A[i];
        if(i == 0){
            if(S[i] == 'M'){
                cntM[i][n] = 1;
            }
            else if(S[i] == 'X'){
                cntX[i][n] = 1;
            }
        }
        else{
            for(int t = 0; t < 3; t++){
                cntM[i][t] = cntM[i-1][t];
                cntX[i][t] = cntX[i-1][t];
            }
            if(S[i] == 'M'){
                cntM[i][n] += 1;
            }
            else if(S[i] == 'X'){
                cntX[i][n] += 1;
            }
        }
    }
    for(int j = 1; j < N-1; j++){
        if(S[j] != 'E') continue;
        // 左側のMの個数と
        // 右側のXの個数
        int jj = A[j];
        for(int i = 0; i < 3; i++){
            for(int k = 0; k < 3; k++){
                mp[{i,jj,k}] += cntM[j-1][i]*(cntX[N-1][k] - cntX[j][k]);
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){   
                ans += mex[i][j][k] * mp[{i,j,k}];
            }
        }
    }
    cout << ans << endl;
}
