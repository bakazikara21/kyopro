#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = 998244353;

int main(){
    int Q; cin >> Q;
    deque<int> deq;
    for(int q = 0; q < Q; q++){
        int t,x; cin >> t >> x;
        if(t == 1){
            deq.push_front(x);
        }
        if(t == 2){
            deq.push_back(x);
        }
        if(t == 3){
            cout << deq.at(x-1) << endl;
        }
    }
}