#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;
    vector<double> sum(M),num(M);
    for(int i = 0; i < N; i++){
        int A,B;
        cin >> A >> B;
        A--;
        sum[A] += B;
        num[A] += 1.0;
    }
    cout << setprecision(15);
    for(int k = 0; k < M; k++){
        cout << sum[k]/num[k] << endl;
    }
}
