#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        bool ok = false;
        for(int j = i-1; j >= 0; j--){
            if(A[j]>A[i]){
                cout << j+1 << endl;
                ok = true;
                break;
            }
        }
        if(!ok){
            cout << -1 << endl;
        }
    }
}

