#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S;
    cin >> S;   // A,B,Cからなる文字列

    stack<string> stk;
    int siz = (int)S.size();
    for(int i = 0; i < siz; i++){
        if(stk.empty() or S[i] == 'A'){
            string T = "";
            T += S[i];
            stk.push(T);
        }
        else if(stk.top() == "A" and S[i] == 'B'){
            stk.pop();
            stk.push("AB");
        }
        else if(stk.top() == "AB" and S[i] == 'C'){
            stk.pop();
        }
        else{
            string T = "";
            T += S[i];
            stk.push(T);
        }
    }
    vector<string> ans;
    siz = (int)stk.size();
    for(int i = 0; i < siz; i++){
        ans.push_back(stk.top());
        stk.pop();
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0; i < siz; i++){
        cout << ans[i];
    }
    cout << endl;
}
