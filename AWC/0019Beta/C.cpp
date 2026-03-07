#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    int ans = 1;
    for(int i = 1; i < N; i++){
        if(A[i] != A[i-1]+1) ans++;
    }
    cout << ans << endl;
}
