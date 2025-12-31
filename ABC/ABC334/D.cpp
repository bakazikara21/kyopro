#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,Q;
    cin >> N >> Q;
    vector<ll> R(N);
    for(int i = 0; i < N; i++) cin >> R[i];
    sort(R.begin(),R.end());
    for(int i = 0; i < N-1; i++){
        R[i+1] += R[i]; // そりをi+1台引くために必要なトナカイの最小数
    }
    for(int q = 0; q < Q; q++){
        ll X;
        cin >> X;

        int t = upper_bound(R.begin(),R.end(),X)-R.begin();
        cout << t << endl;
    }
}
