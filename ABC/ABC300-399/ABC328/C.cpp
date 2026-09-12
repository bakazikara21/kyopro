#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vector<int> ruiseki(N);
    for(int i = 1; i < N; i++){
        if(S[i]==S[i-1]){
            ruiseki[i] = ruiseki[i-1]+1;
        }
        else{
            ruiseki[i] = ruiseki[i-1];
        }
    }

    for(int q = 0; q < Q; q++){
        int l,r;
        cin >> l >> r;
        l--; r--;
        cout << ruiseki[r]-ruiseki[l] << endl;
    }
}
