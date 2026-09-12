#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

/*
    後ろから考える
*/
int main(){
    int N,Q;
    cin >> N >> Q;
    vector<int> num(Q),P(Q);
    vector<string> S(Q);
    for(int q = 0; q < Q; q++){
        cin >> num[q];

        if(num[q] == 1){
            cin >> P[q];
        }
        if(num[q] == 2){
            cin >> P[q] >> S[q];
            reverse(S[q].begin(),S[q].end());
        }
        if(num[q] == 3){
            cin >> P[q];
        }
    }
    /*
        クエリを逆から再帰的に求めに行く
    */
    int search = 0; // PC0が最後に何で置き換えられたか知りたい。
    string ans = "";    // 文字列はリバースして計算していかないとTLEするらしい
    for(int q = Q-1; q >= 0; q--){
        if(num[q] == 1){
            // PC0の文字列でP[q]を置き換える
            if(search == P[q]){
                search = 0; // じゃあPC0が最後に何で置き換えられたかわかればよい
            }
        }
        if(num[q] == 2){
            // PCP[q]の末尾にS[q]を付け足す
            if(P[q] == search){
                ans += S[q];
            }
        }
        if(num[q] == 3){
            // PCP[q]の文字列でPC0を置き換える
            if(search == 0){
                // PC0は最後にP[q]で置き換えられた
                search = P[q]; // じゃあP[q]が最後に何で置き換えられたかわかればよい
            }
        }
    }
    reverse(ans.begin(),ans.end()); // リバースしていたのを戻す
    cout << ans << endl;
}
