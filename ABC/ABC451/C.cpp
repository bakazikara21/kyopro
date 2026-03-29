#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int Q; cin >> Q;
    int ans = 0;
    map<int,int> mp;
    for(int q = 0; q < Q; q++){
        int num,h; cin >> num >> h;
        if(num == 1){
            ans++;
            mp[h]++;
        }
        else{
            auto itr = mp.begin();
            while(itr != mp.end()){
                auto [key,val] = *itr;
                if(key <= h){
                    ans -= val;
                    itr = mp.erase(itr);
                }
                else break;
            }
        }
        cout << ans << endl;
    }
}
