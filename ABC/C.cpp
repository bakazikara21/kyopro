#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        A[i]--;
    }
    int ans = 1;
    int power = A[0];
    int i = 1;
    while(i < N and power > 0){
        power--;
        power = max(power,A[i]);
        i++;
        ans++;
    }
    cout << ans << endl;
}
