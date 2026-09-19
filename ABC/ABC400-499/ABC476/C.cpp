#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int Large,Mid,Small = 0;
    for(int k = 0; k < 2; k++){
        if(k == 0){
            Large = A[k];
        }
        else {
            if(Large < A[k]){
                Mid = Large;
                Large = A[k];
            }
            else Mid = A[k];
        }
    }
    for(int k = 2; k < N; k++){
        if(Small > A[k]){

        }
        else if(Mid > A[k]){
            Small = A[k];
        }
        else if(Large > A[k]){
            Small = A[k];
            swap(Small,Mid);
        }
        else{
            Small = Mid;
            Mid = Large;
            Large = A[k];
        }
        cout << Small << endl;
    }
}
