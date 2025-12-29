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
    vector<vector<ll>> Ruisekirow(N,vector<ll>(N+1)),Ruisekicolumn(N+1,vector<ll>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            
            Ruisekirow[i][j+1] = Ruisekirow[i][j]+(S[i][j] == 'o');
        }
    }
    for(int j = 0; j < N; j++){
        for(int i = 0; i < N; i++){
            Ruisekicolumn[i+1][j] = Ruisekicolumn[i][j]+(S[i][j] == 'o');
        }
    }

    ll ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(S[i][j] == 'x') continue;

            ll I = Ruisekirow[i][N]-Ruisekirow[i][j+1];
            ll J = Ruisekicolumn[N][j]-Ruisekicolumn[i+1][j];
            I += Ruisekirow[i][j];
            J += Ruisekicolumn[i][j];
            ans += I*J;
        }
    }
    cout << ans << endl;
}
