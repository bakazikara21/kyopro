#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
後ろからスタックを使って単調増加列を管理
-> Tessoku-A60
*/
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    vector<int> ans(N);
    stack<int> stk;
    for(int i = N-1; i >= 0; i--){
        ans[i] = (int)stk.size();
        if(stk.empty()){
            stk.push(A[i]);
        }
        else{
            while(!stk.empty() and A[i] >= stk.top()){
                stk.pop();
            }
            stk.push(A[i]);
        }
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
