#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
int sumDigit(int num){
    int sum = 0;
    while(num > 0){
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}
int main(){
    int N,K;
    cin >> N >> K;

    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(sumDigit(i) == K){
            ans++;
        }
    }
    cout << ans << endl;
}
