#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    sort(A.begin(),A.end());
    if(N%2 == 1){
        cout << A[N-1] << endl;
        return 0;
    }
    ll num = A[N-1]+A[0];
    bool ok = true;
    for(int i = 0; i < N; i++){
        if(num != (A[i]+A[N-1-i])){
            ok = false;
            break;
        }
    }
    set<ll> st;
    if(ok){
        st.insert(num);
    }

    ok = true;
    int imax = N-1;
    while(imax > 0 and A[imax] == A[imax-1]){
        imax--;
    }
    if(imax == 0){
        st.insert(A[imax]);
    }
    else if(imax%2 == 0){

        num = A[imax-1]+A[0];
        for(int i = 0; i < imax; i++){
            if(num != (A[i]+A[imax-1-i])){
                ok = false;
                break;
            }
        }
        if(imax > 0 and num != A[imax]){
            ok = false;
        }
        if(ok){
            st.insert(num);
        }
    }
    for(ll a : st){
        cout << a << " ";
    }
    cout << endl;
}
