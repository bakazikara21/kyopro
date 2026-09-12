#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int X;
    cin >> X;

    int x = X;
    vector<int> bit;
    while(x > 0){
        int p = (x%10);
        bit.push_back(p);
        x /= 10;
    }
    sort(bit.begin(),bit.end());
    int keta = bit.size();
    int mini = 0;
    while(bit[mini] == 0){
        mini++;
    }
    swap(bit[0],bit[mini]);

    int ten = 1; int ans = 0;
    for(int i = 0; i < keta; i++){
        ans += bit[keta-1-i]*ten;
        ten *= 10;
    }
    cout << ans << endl;
}
