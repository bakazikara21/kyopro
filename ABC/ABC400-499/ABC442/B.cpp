#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int Q;
    cin >> Q;
    int vol = 0;
    int play = 0;
    for(int q = 0; q < Q; q++){
        int A;
        cin >> A;
        if(A == 1){
            vol++;
        }
        if(A == 2){
            vol = max(0,vol-1);
        }
        if(A == 3){
            play = 1-play;
        }
        if(vol >= 3 and play == 1){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}
