#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> A(N);
    pair<int,int> tar = {0,0};
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(tar.first < A[i]){
            tar.first = A[i];
            tar.second = i;
        }
    }
    cout << tar.second+1 << endl;
}
