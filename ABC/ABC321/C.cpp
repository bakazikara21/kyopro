#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll K;
    cin >> K;
    vector<ll> likeNum;
    // 最上位ビットnum, 現在の文字列S
    auto dfs = [&](auto self, int num, string S)->void{
        if(num == 9) return;

        for(int i = num+1; i < 10; i++){
            string s = to_string(i);
            ll like = stoll(s+S);
            likeNum.push_back(like);
            self(self,i,s+S);
        }
    };
    for(int i = 0; i < 10; i++){
        string S = to_string(i);
        likeNum.push_back(i);   // 0も含めちゃう
        dfs(dfs,i,S);
    }
    sort(likeNum.begin(),likeNum.end());
    cout << likeNum[K] << endl;
}
