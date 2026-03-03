#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 2147483647;

/*
    String Hash:
    
*/
int main(){
    int N,Q;
    string S;
    cin >> N >> Q >> S;

    vector<ll> Hash(N+1, 0);
    vector<ll> power(N+1, 1);
    for (int i = 0; i < N; i++) {
        Hash[i+1] = (Hash[i] * 100 + (S[i] - 'a')) % mod;
        power[i+1] = (power[i] * 100) % mod;
    }

    for(int q = 0; q < Q; q++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
       
        ll hashAB = (Hash[b] - Hash[a-1] * power[b-a+1] % mod + mod) % mod;
        ll hashCD = (Hash[d] - Hash[c-1] * power[d-c+1] % mod + mod) % mod;
       

        if(hashAB == hashCD){
            cout << "Yes" << endl;
        }else{
            cout << "No " << endl;
        }
    }
}