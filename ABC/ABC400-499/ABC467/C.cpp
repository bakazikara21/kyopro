#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    vector<int> A(N),B(N-1);
    for(auto& a : A) cin >> a;
    for(auto& b : B) cin >> b;

    int ans0 = 0, add = 0;
    for(int i = 0; i < N-1; i++){
        if((A[i+1]+A[i]+add)%M == B[i]%M){
            add = 0;
        }
        else {
            add = 1;
            ans0++;
        }
    }
    int ans1 = 1;
    add = 1;
    for(int i = 0; i < N-1; i++){
        if((A[i+1]+A[i]+add)%M == B[i]%M){
            add = 0;
        }
        else {
            add = 1;
            ans1++;
        }
    }
    cout << min(ans0,ans1) << endl;
}
