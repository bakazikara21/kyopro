#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,L,R; cin >> N >> L >> R;
    string S; cin >> S;
    int r = 0;
    vector<int> sint(N);
    for(int i = 0; i < N; i++){
        sint[i] = S[i]-'a';
    }
    vector<vector<int>> prefix(26,vector<int>(N+1));
    for(int i = 0; i < N; i++){
        int num = sint[i];
        prefix[num][i] = 1;
    }
    for(int i = 0; i < 26; i++){
        for(int j = 1; j <= N; j++){
            prefix[i][j] += prefix[i][j-1];
        }
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        // 右端固定
        int num = sint[i];
        int r = R+i;
        int l = L+i;
        if(r >= N) r = N;
        if(l >= N) l = N;
        ans += prefix[num][r]-prefix[num][l-1];
    }
    cout << ans << endl;
}
