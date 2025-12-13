#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;

    vector<int> j;
    for(int i = 1; i < 10; i++){
        if(N%i == 0){
            j.push_back(i);
        }
    }

    for(int i = 0; i <= N; i++){
        bool ok = false;
        for(int jj : j){
            if(i % (N/jj) == 0){
                cout << jj;
                ok = true;
                break;
            }
        }
        if(!ok){
            cout << '-';
        }
    }
    cout << endl;
}
