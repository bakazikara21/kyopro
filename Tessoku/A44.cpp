#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        A[i] = i+1;
    }
    bool reverse = false;
    for(int q = 0; q < Q; q++){
        int num;
        cin >> num;
        if(num == 1){
            int x,y;
            cin >> x >> y;
            x--;
            if(reverse == true){
                A[N-1-x] = y;
            }else{
                A[x] = y;
            }
        }
        if(num == 2){
            // reverse
            reverse = 1-reverse;
        }
        if(num == 3){
            int x;
            cin >> x;
            x--;
            if(reverse == true){
                cout << A[N-1-x] << endl;
            }else{
                cout << A[x] << endl;
            }
        }
    }
}
