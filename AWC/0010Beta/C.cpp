#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K,Q;
    cin >> N >> K >> Q;
    vector<int> A(N),B(N);
    int kind = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(i == 0){
            B[i] = kind;
        }
        else if(abs(A[i]-A[i-1]) <= K){
            B[i] = kind;
        }
        else {
            kind++;
            B[i] = kind;
        }
    }
    for(int q = 0; q < Q; q++){
        int L,R;
        cin >> L >> R; L--; R--;
        if(B[L] == B[R]){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}
