#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> A(M);
    for(int i = 0; i < M; i++){
        cin >> A[i];
    }
    int j = 0;
    for(int i = 1; i <= N; i++){
        while(j < M and i > A[j]){
            j++;
        }
        cout << A[j]-i << endl;
    }
}
