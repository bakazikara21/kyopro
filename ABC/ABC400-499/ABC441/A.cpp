#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int P,Q,X,Y;
    cin >> P >> Q >> X >> Y;
    for(int i = P; i < P+100; i++){
        for(int j = Q; j < Q+100; j++){
            if(i == X and j == Y){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
