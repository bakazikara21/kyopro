#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; string T;
    cin >> N >> T;
    
    int siz = (int)T.size(); // Tの文字数
    // Tの0文字目からx文字目までと一致するか
    // Tのy文字目からN文字目までと一致するか
    vector<int> A(N);    //0からx文字目までを持っている
    vector<int> B(N);    //yからN-1文字目までを持っている
    for(int i = 0; i < N; i++){
        string S;
        cin >> S;

        int Siz = (int)S.size();
        int st = 0,en = siz-1;
        for(int j = 0; j < Siz; j++){
            if(S[j] == T[st]) st++;
            if(S[Siz-1-j] == T[en]) en--;
        }
        
        A[i] = st;    //1からst文字目までを持っている
    
    
        B[i] = siz-en-1;    //en+2からN文字目までを持っている
        //cout << "B[i] = " << B[i] << endl;
    }
    // A[i]+B[j] >= |T|なるjを高速に求めればよい
    // 固定したiに対して、B[j] >= |T|-A[i]なるjの個数を高速に求めればよい
    sort(B.begin(),B.end());

    ll ans = 0;
    for(int i = 0; i < N; i++){
        int t = lower_bound(B.begin(),B.end(),siz-A[i])-B.begin();

        ans += N-t;
        //cout << "t = " << t << " A[i] = " << A[i] << endl;
    }
    cout << ans << endl;
}
