#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll a,b,C;
    cin >> a >> b >> C;
    bool change = false;
    if(a > b){
        change = true;
        swap(a,b);
        // a <= bとする
    }
    
    ll c = 0;   // Cを2進法で表現した時の1の個数 = c
    for(int i = 0; i < 60; i++){
        if((C >> i) & 1){
            c++;
        }
    }
    
    /*
    Xを2進法で表現した時の1の個数 = a
    Yを2進法で表現した時の1の個数 = b
    Y = C^Xより、b = c+a, c+a-2, c+a-4, ...なら可能
    */
    ll Y = C;
    ll dif = c+a - b;
    ll cnt1 = (c+a-b) / 2;   // Cの1を0に変更する回数
    ll cnt2 = a - cnt1;   // Cの0を1に変更する回数
    if(dif%2 == 1 or dif < 0 or cnt1 > c or cnt2 > (60-c) or cnt2 < 0){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < 60; i++){
        if((C >> i) & 1 and cnt1 > 0){
            // Cのiビット目の1を0に変更->これらを合計cnt1回繰り返す
            Y ^= (1LL << i);
            cnt1--;
        }
        else if(((C >> i) & 1) == 0 and cnt2 > 0){
            // Cのiビット目の0を1に変更->これらを合計cnt2回繰り返す
            Y |= (1LL << i);
            cnt2--;
        }
    }
    ll X = C^Y;
    if(!change) cout << X << " " << Y << endl;
    else cout << Y << " " << X << endl;
}