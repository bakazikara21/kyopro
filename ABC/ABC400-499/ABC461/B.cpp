#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<int> A(N),B(N);
    for(int i = 0; i < N; i++) cin >> A[i],A[i]--;
    for(int i = 0; i < N; i++) cin >> B[i],B[i]--;

    bool ok = true;
    for(int i = 0; i < N; i++){
        if(B[A[i]] != i){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}
