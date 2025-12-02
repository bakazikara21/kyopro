#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,S;
    cin >> N >> S;
    vector<bool> exist(S+1,false);
    exist[0] = true;
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        for(int s = S; s >= A; s--){
            if(exist[s-A] == true){
                exist[s] = true;
            }
        }
    }
    if(exist[S]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}