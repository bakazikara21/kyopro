#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int popcount(ll x){
    int cnt = 0;
    while(x > 0){
        if(x%2 == 1){
            cnt++;
        }
        x /= 2;
    }
    return cnt;
}
int main(){
    string S;
    cin >> S;

    string T = S;
    int siz = (int)S.size();
    for(int i = 0; i < siz; i++){
        char c = T[i];
        if(c >= 'a' and c <= 'z'){
            T[i] = 'A' + (c-'a');
        }
        if(c >= 'A' and c <= 'Z'){
            T[i] = 'a' + (c-'A');
        }
    }
    int Q;
    cin >> Q;
    for(int q = 0; q < Q; q++){
        ll K;
        cin >> K;
        
        K--;
        ll syo = K/siz;
        ll r = K%siz;
        // S[r] or T[r] -> 50%で正解できる
        
        if(popcount((ll)syo)%2 == 1) cout << T[r] << " ";
        else cout << S[r] << " ";
        //cout << "(1LL << left) = " << (1LL << left) << " syo = " << syo << endl;
    }
    cout << endl;
}
