#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int W,B;
    cin >> W >> B;

    string S = "wbwbwwbwbwbw";
    string T = "";
    for(int i = 0; i < 30; i++){
        T = T + S;
    }
    set<pair<int,int>> se;
    for(int i = 0; i < T.size(); i++){
        int w = 0, b = 0;
        for(int j = 0; i+j < T.size(); j++){
            if(T[i+j] == 'w'){
                w++;
            }else{
                b++;
            }
            se.insert({w,b});
        }
    }
    if(se.count({W,B})){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
