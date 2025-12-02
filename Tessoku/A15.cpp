#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N),copy(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        copy[i] = A[i];
    }
    sort(copy.begin(),copy.end());

    map<int,int> mp;
    int rank = 1;
    int num = copy[0];
    //cout << num << endl;
    for(int i = 0; i < N; i++){
        if(num < copy[i]){
            rank++;
            num = copy[i];
        }
        mp[copy[i]] = rank;
    }
    for(int i = 0; i < N; i++){
        cout << mp[A[i]] << " ";
    }
    cout << endl;
}
