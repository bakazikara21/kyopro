#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S;
    cin >> S;
    ll ans = 0;
    int lastNum = 10;
    int preCount = 0;
    int nowCount = 0;
    for(int i = 0; i < S.size(); i++){
        if(i == 0){
            lastNum = S[i]-'0';
            preCount++;
        }else{
            if((S[i]-'0') == lastNum){
                preCount++;
            }else if((S[i]-'0') == lastNum+1){
                nowCount++;
                ans++;
                //cout << i << " " << preCount << " " << nowCount << endl;
                while(preCount > nowCount and (i+1 < S.size()) and (S[i+1]-'0') == lastNum+1){
                    i++;
                    nowCount++;
                    ans++;
                    //cout << i << " " << preCount << " " << nowCount  << " while" << endl;
                } 
                preCount = nowCount;
                nowCount = 0;
                lastNum = S[i]-'0';
            }else{
                preCount = 1;
                nowCount = 0;
                lastNum = S[i]-'0';
            }
        }
    }
    cout << ans << endl;
}

