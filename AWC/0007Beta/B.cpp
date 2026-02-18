#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> M(N);
    vector<vector<string>> W(N);
    vector<set<string>> st(N);
    for(int i = 0; i < N; i++){
        cin >> M[i];
        for(int j = 0; j < M[i]; j++){
            string S;
            cin >> S;
            W[i].push_back(S);
            st[i].insert(S);
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            // i,jが共同研究できるか
            int cnt = 0;
            int kmax = M[i];
            for(int k = 0; k < kmax; k++){
                if(st[j].count(W[i][k])) cnt++;
            }
            if(cnt >= K) ans++;
        }
    }
    cout << ans << endl;
}
