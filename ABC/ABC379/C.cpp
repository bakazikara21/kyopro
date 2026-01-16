#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;
    vector<ll> X(M),A(M);
    vector<pair<ll,ll>> pairs(M);
    for(int i = 0; i < M; i++){
        cin >> X[i];
    }
    ll sum = 0;
    for(int i = 0; i < M; i++){
        cin >> A[i];
        sum += A[i];
    }
    if(sum != N){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < M; i++){
        pairs[i] = {X[i],A[i]};
    }
    sort(pairs.begin(),pairs.end());
    ll sofar = 1;
    ll ans = 0;
    for(int i = 0; i < M; i++){
        auto [x,num] = pairs[i];
        //cout << "num = " << num << endl;
        if(x > sofar){
            cout << -1 << endl;
            return 0;
        }
        ans += num*(num-1)/2;
        if(i+1 < M){
            ll nx = pairs[i+1].first;
            
            ans -= (num-(nx-x)-1)*(num-(nx-x))/2;
            pairs[i+1].second += num-(nx-x);
            //cout << "minus = " << (num-(nx-x))*(num-(nx-x)+1)/2 << endl;
        }
        
        sofar += num-(sofar-x);
        //cout << "sofar = " << sofar << endl;
    }
    cout << ans << endl;
}
