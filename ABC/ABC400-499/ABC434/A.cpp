#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int W,B;
    cin >> W >> B;
    int cnt = 1;
    W *= 1000;
    while(W >= B*cnt){
        cnt++;
    }
    cout << cnt << endl;
}
