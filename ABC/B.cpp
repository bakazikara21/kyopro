#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    int cnt = 0;
    for(int l = 0; l < N; l++){
        for(int r = l; r < N; r++){
            bool ok = true;
            int sum = 0;
            for(int i = l; i <= r; i++){
                sum += A[i];
            }
            for(int i = l; i <= r; i++){
                if(sum%A[i] == 0){
                    ok = false;
                    break;
                }
            }
            if(ok){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
