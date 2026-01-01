#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    ll n = N-1;
    if(N==1){
        cout << 0 << endl;
        return 0;
    }

    vector<int> digits = {0,2,4,6,8};   // 5進数
    vector<int> fives;
    while(n > 0){
        fives.push_back(digits[n%5]);
        n /= 5;
    }
    reverse(fives.begin(),fives.end());
    for(int num : fives){
        cout << num;
    }
    cout << endl;
}
