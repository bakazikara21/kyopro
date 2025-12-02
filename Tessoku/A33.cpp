#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// XOR = 0で出番がまわってきたら負け確
// XOR != 0で出番がまわってきたら勝ち確
// つまり、XOR = 0になるように操作可能ということ
// 負け確、勝ち確がこれで決まる理由はわからない
// 最後はすべてのA_iが0で回ってくると負けが決まる
// ->XOR = 0で出番がまわってきたら負け確
int main(){
    int N;
    cin >> N;
    int XOR = 0;
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        XOR ^= A;
    }
    if(XOR == 0){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
    }

}
