#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;

    string S,T;
    cin >> S >> T;

    string t = T;
    int ans = (int)1e8;
    for(int i = 0; i < (int)(S.size()-T.size()+1); i++){
        // はじめの場所
        int cnt = 0;
        for(int j = 0; j < T.size(); j++){
            int numS = S[i+j]-'0';
            int numT = T[j]-'0';
            if(numS-numT >= 0){
                cnt += numS-numT;
            }else{
                cnt += (10-numT)+numS;
            }
        }
        ans = min(ans,cnt);
    }
    cout << ans << endl;
}
