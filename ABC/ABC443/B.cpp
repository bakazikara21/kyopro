#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N,K;
    cin >> N >> K;

    ll left = -1;
    ll right = K;
    ll mid = (right+left)/2;
    while((right-left) > 1){
        ll sum = N*(mid+1) + mid*(mid+1)/2;
        if(sum >= K){
            right = mid;
        }
        else left = mid;
        mid = (right+left)/2;
    }
    cout << right << endl;
}
