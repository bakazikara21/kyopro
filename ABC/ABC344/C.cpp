#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int M;
    cin >> M;
    vector<ll> B(M);
    for(int i = 0; i < M; i++) cin >> B[i];

    int L;
    cin >> L;
    vector<ll> C(L);
    for(int i = 0; i < L; i++) cin >> C[i];

    set<ll> st;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < L; k++){
                st.insert(A[i]+B[j]+C[k]);
            }
        }
    }

    int Q;
    cin >> Q;
    for(int q = 0; q < Q; q++){
        ll X;
        cin >> X;
        if(st.count(X)){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}
