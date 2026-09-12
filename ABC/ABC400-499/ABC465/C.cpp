#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    string S; cin >> S;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        A[i] = i+1;
    }
    deque<int> deq;
    bool flip = false;
    for(int i = 0; i < N; i++){
        if(S[i] == 'o'){
            flip = flip xor 1;
        }
        if(!flip and S[i] == 'o')deq.push_front(A[i]);
        else if(flip and S[i] == 'x') deq.push_front(A[i]);
        else deq.push_back(A[i]);
    }
    if(flip) reverse(deq.begin(),deq.end());
    for(int i = 0; i < N; i++){
        cout << deq[i] << " ";
    }
    cout << endl;
}
