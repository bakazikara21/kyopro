#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;

    vector<ll> cntt(N+1);
    vector<ll> ans;
    for(int x = 1; 2*x*x < N; x++){
        for(int y = x+1; x*x+y*y <= N; y++){
            cntt[x*x+y*y]++;
        }
    }
    for(int i = 5; i <= N; i++){
        if(cntt[i] == 1){
            ans.push_back(i);
        }
    }
    sort(ans.begin(),ans.end());

    cout << ans.size() << endl;
    for(ll v : ans){
        cout << v << " ";
    }
    cout << endl;
}
