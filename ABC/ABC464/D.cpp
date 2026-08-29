#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
const int inf = (int)1e9;

int main(){
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        int N; cin >> N;
        string S; cin >> S;
        vector<ll> X(N),Y(N-1);
        for(auto &x : X) cin >> x;
        for(auto &y : Y) cin >> y;
        vector<ll> rain(N),sun(N);
        for(int i = 0; i < N-1; i++){
            if(i == 0){
                if(S[i] == 'S'){
                    rain[i] = -X[i];
                }
                else sun[i] = -X[i];
            }
            if(S[i+1] == 'S'){
                rain[i+1] = max(rain[i] - X[i+1], sun[i] - X[i+1]);
                sun[i+1] = max(sun[i],rain[i]+Y[i]);
            }
            else{
                rain[i+1] = max(rain[i] , sun[i]);
                sun[i+1] = max(sun[i]- X[i+1],rain[i]+Y[i]- X[i+1]);
            }
        }
        cout << max(rain[N-1],sun[N-1]) << endl;
    }
}
