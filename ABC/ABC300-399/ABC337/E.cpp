#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// むずすぎ
int main(){
    int N;
    cin >> N; // N <= 100;

    // N本のジュースのうち、1本腐っている
    // M = log2(N)人いれば、N本のどれが腐っているか判別可能
    int M = 0;
    int n = 1;
    while(N > n){
        n *= 2;
        M++;
    }

    cout << M << endl;

    // ジュース0,1,2,3,...,N-1は2進法のM桁ですべて表すことができる
    for(int i = 0; i < M; i++){
        // 人iは cnt 個飲ませる
        int cnt = 0;
        for(int j = 0; j < N; j++){
            if((j >> i) & 1){
                cnt++;
            }
        }
        cout << cnt << " ";
        for(int j = 0; j < N; j++){
            if((j >> i) & 1){
                cout << j+1 << " ";
            }
        }
        cout << endl;
    }
    // 翌日、
    string S;
    cin >> S;

    int num = 1;
    int ans = 0;
    for(int i = 0; i < M; i++){
        if(S[i] == '1'){
            ans += num;
        }
        num *= 2;
    }
    cout << ans+1 << endl;
}
