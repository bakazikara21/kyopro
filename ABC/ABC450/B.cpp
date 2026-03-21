#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<vector<ll>> C(N,vector<ll>(N));
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            cin >> C[i][j];
        }
    }
    for(int a = 0; a < N; a++){
        for(int c = a+2; c < N; c++){
            ll cost = C[a][c];
            //cout << "a = " << a << " c = " << c << " C[a][c] = " << C[a][c] << endl;
            for(int b = a+1; b < c; b++){
                ll cs = C[a][b]+C[b][c];
                if(cost > cs){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}
