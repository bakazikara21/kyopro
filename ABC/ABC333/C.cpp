#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    N--;

    int M = 12;
    vector<ll> A(M);
    ll one = 1;
    for(int i = 0; i < M; i++){
        if(i==0) A[i] = one;
        else A[i] = A[i-1] + one;
        one *= 10;
    }
    vector<ll> ans;
    for(int i = 0; i < M; i++){
        for(int j = i; j < M; j++){
            for(int k = j; k < M; k++){
                ans.push_back(A[i]+A[j]+A[k]);
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans[N] << endl;
}
