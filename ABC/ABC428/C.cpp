#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const int inf = 1e9;
const ll mod = 1e9 + 7;

int main(){
    int Q;
    cin >> Q;
    string S = "";
    int left = 0, right = 0;
    int index = inf;
    for(int i = 0; i < Q; i++){
        int num;
        cin >> num;

        if(num == 1){
            char c;
            cin >> c;
            S.push_back(c);
            if(c == '('){
                left++;
            }else{
                right++;
            }
            
            if(left < right){
                // 良くない括弧列
                index = min(index,(int)S.size()-1);
            }
        }
        if(num == 2){
            char c = S[S.size()-1];
            if(c == '('){
                left--;
            }else{
                right--;
            }
            S.pop_back();

            if((int)S.size()-1 < index){
                index = inf;
            }
        }
        // Sが良い括弧列かどうか
        if(left == right and index == inf){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}