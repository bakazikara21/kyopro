#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    vector<int> A(3);
    cin >> A[0] >> A[1] >> A[2];

    sort(A.begin(),A.end());
    int ans = A[0]+A[1]*10+A[2]*100;

    cout << ans << endl;
}
