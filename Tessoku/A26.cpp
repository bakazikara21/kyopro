#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int Q;
    cin >> Q;
    for(int q = 0; q < Q; q++){
        int X;
        cin >> X;
        bool flag = true;
        // 素数判定
        for(int x = 2; x*x <= X; x++){
            if(X%x == 0){
                cout << "No" << endl;
                flag = false;
                break;
            }
        }
        if(flag == true){
            cout << "Yes" << endl;
        }
    }
}
