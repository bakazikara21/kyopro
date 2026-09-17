#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<ll> A(N),B(N);
    vector<tuple<ll,ll,int>> ans(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
        ans[i] = {A[i],B[i],i};
    }
    sort(ans.begin(),ans.end(),[&](tuple<ll,ll,int> &a, tuple<ll,ll,int> &b)->bool{
        auto [a1,b1,id1] = a;
        auto [a2,b2,id2] = b;
        if(a1*(a2+b2) == a2*(a1+b1)) return (id1 > id2);
        return (a1*(a2+b2) < a2*(a1+b1));
    });
    for(int i = N-1; i >= 0; i--){
        auto [a,b,id] = ans[i];
        cout << id + 1 << " ";
    }
    cout << endl;
}
