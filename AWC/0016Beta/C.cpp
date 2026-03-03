#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,L,R,T; cin >> N >> L >> R >> T;
    vector<tuple<int,int,int>> ans;
    for(int i = 0; i < N; i++){
        int P,S; cin >> P >> S;
        if(L <= P and P <= R and S >= T){
            ans.push_back({P,-S,i});
        }
    }
    if((int)ans.size() == 0){
        cout << -1 << endl;
        return 0;
    }
    sort(ans.begin(),ans.end());
    auto [p,s,i] = ans[0];
    cout << i+1 << endl;
}
