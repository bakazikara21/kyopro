#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    vector<int> A(N),B(M),AB;
    for(int &a : A){ 
        cin >> a;
        AB.push_back(a);
    }
    for(int &b : B){
        cin >> b;
        AB.push_back(b+1);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(AB.rbegin(),AB.rend());
    int ans = inf;
    for(auto X : AB){
        // X以下の個数
        int a = (upper_bound(A.begin(),A.end(),X+1)-A.begin());

        // X以上の個数
        int b = M - (lower_bound(B.begin(),B.end(),X)-B.begin());
        // cout << "X = " << X << " a = " << a << " b = " << b << endl;
        if(a >= b) ans = X;
        if(a < b){
            break;
        }
    }
    cout << ans << endl;
}
