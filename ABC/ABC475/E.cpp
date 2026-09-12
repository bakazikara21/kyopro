#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M,K; cin >> N >> M >> K;
    string T; cin >> T;
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }

    int Q; cin >> Q;
    for(int q = 0; q < Q; q++){
        int i,j; cin >> i >> j;
        i--; j--;
        if(S[i][j] == 'o') S[i][j] = 'x';
        else S[i][j] = 'o';

        // 参加者 i は予選通過できますか？
    }
}
