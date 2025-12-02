#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int N,M;
        cin >> N >> M;
        vector<int> X(N),Y(M);
        for(int i = 0; i < N; i++) cin >> X[i];
        for(int i = 0; i < M; i++) cin >> Y[i];

        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        
    }
}

