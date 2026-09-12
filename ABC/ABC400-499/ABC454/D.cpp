#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int T; cin >> T;    // ()とxからなる文字列
    for(int t = 0; t < T; t++){
        string A,B; cin >> A >> B;
        int Na = (int)A.size();
        int Nb = (int)B.size();
        if((Na % 2) != (Nb % 2)){
            cout << "No" << endl;
            continue;
        }
        // int X = 0;  // xの個数は等しくないとNo
        // for(int i = 0; i < Na; i++){
        //     if(A[i] == 'x') X++;
        // }
        // for(int i = 0; i < Nb; i++){
        //     if(B[i] == 'x') X--;
        // }
        // if(X != 0){
        //     cout << "No" << endl;
        //     continue;
        // }
        // 外せる括弧を両方とも外して一致していればよい
        set<int> ida;    // 外せる括弧のindex(A)
        set<int> idb;    // 外せる括弧のindex(B)
        int left = 0, right = 0;
        for(int i = 0; i < Na-1; i++){
            if(A[i] == A[i+1] and A[i] == 'x'){
                left = i-1;
                right = i+2;    // 外せる括弧のindexの候補
                while(left >= 0 and right < Na and A[left] == '(' and A[right] == ')'){
                    ida.insert(left);
                    ida.insert(right);
                    left--;
                    right++;
                }
                i = right;
            }
        }
        string S = "";
        for(int i = 0; i < Na; i++){
            if(ida.count(i)) continue;
            S += A[i];
        }
        left = 0, right = 0;
        for(int i = 0; i < Nb-1; i++){
            if(B[i] == B[i+1] and B[i] == 'x'){
                left = i-1;
                right = i+2;    // 外せる括弧のindexの候補
                while(left >= 0 and right < Nb and B[left] == '(' and B[right] == ')'){
                    idb.insert(left);
                    idb.insert(right);
                    left--;
                    right++;
                }
                i = right;
            }
        }
        string T = "";
        for(int i = 0; i < Nb; i++){
            if(idb.count(i)) continue;
            T += B[i];
        }
        //cout << "A -> " << S << " B -> " << T << " : ";
        if(S == T){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}
