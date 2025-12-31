#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll A,M,L,R;
    cin >> A >> M >> L >> R;    
    // A->基準の座標
    // M->Aの位置から東西にMメートルおきにクリスマスツリーを立てる
    // L~Rの間に立っているクリスマスツリーの本数を求めよ

    R -= A;
    L -= A;
    if(L > 0){
        cout << R/M - (L-1)/M << endl;
    }
    else if(R < 0){
        cout << (R+1)/M - L/M << endl;
    }
    else {
        cout << R/M - L/M + 1 << endl;
    }
}
