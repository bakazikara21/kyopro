#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = (ll)1e9 + 7;
int main(){
    int N;
    cin >> N;
    ll A,B;
    cin >> A >> B;

    vector<ll> D(N);
    for(int i = 0; i < N; i++){
        cin >> D[i];
        D[i] %= (A+B);
    }
    sort(D.begin(),D.end());
    // 連続する D[x]~D[x+N-1] のmax-minがA以下ならYes
    for(int x = 0; x < N; x++){
        if(x==0 and D[N-1]-D[0] < A){
            cout << "Yes" << endl;
            return 0;
        }
        else if(x > 0 and (D[x-1]+A+B) - D[x] < A){
                cout << "Yes" << endl;
                return 0;
        }
    }
    cout << "No" << endl;
}
/*
5 2 5
2 9 15 16 16

*/