#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int N;
        cin >> N;
        vector<int> A(2*N),left(2*N),right(2*N),id(N+1);
        set<int> st;
        for(int i = 0; i < 2*N; i++){
            cin >> A[i];
            if(st.count(A[i])){
                id[A[i]] = i;
            }
            else st.insert(A[i]);
            if(i >= 1){
                right[i-1] = A[i];
                left[i] = A[i-1];
            }
        }
        ll ans = 0;
        for(int i = 0; i < 2*N-1; i++){
            // 前から順に右の整数を見る
            if(A[i] == A[i+1]){
                i++;
                continue;
            }
            int idfirst = i+1;  // A[i]の右側の整数の添え字
            int idsecond = id[A[i+1]];
            if(idsecond-idfirst <= 1) continue;
            
            if(idsecond > 0 and A[idsecond-1] == A[i]){
                ans++;
            }
            else if(idsecond+1 < 2*N and A[idsecond+1] == A[i]){
                ans++;
            }
        }
        cout << ans << endl;
    }
}
