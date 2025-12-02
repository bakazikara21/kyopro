#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int X,N;
    cin >> X >> N;

    vector<int> W(N);
    for(int i = 0; i < N; i++) cin >> W[i];

    int Q;
    cin >> Q;
    vector<bool> used(N,false);
    for(int i = 0; i < Q; i++){
        int P;
        cin >> P;
        P--;
        if(used[P] == true){
            X -= W[P];
            used[P] = false;
        }else{
            X += W[P];
            used[P] = true;
        }
        cout << X << endl;
    }
}