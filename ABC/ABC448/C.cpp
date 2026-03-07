#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,Q; cin >> N >> Q;
    vector<int> A(N),C(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        C[i] = A[i];
    }
    vector<int> st(6);    // 最小値を6個もっておく
    sort(C.begin(),C.end());
    for(int i = 0; i < 6; i++){
        st[i] = C[i];
    }
    for(int q = 0; q < Q; q++){
        int K; cin >> K;
        vector<int> a(K);
        for(int k = 0; k < K; k++){
            int B; cin >> B; B--;
            a[k] = A[B];
        }
        sort(a.begin(),a.end());
        int i = 0;
        while(i < K and st[i]==a[i]){
            i++;
        }
        cout << st[i] << endl;
    }
}
