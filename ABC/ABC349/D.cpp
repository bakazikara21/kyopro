#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll L,R;
    cin >> L >> R;

    vector<pair<ll,ll>> ans;

    ll i = 0,j = 0;
    while(L%2 == 0 and L > 0){
        L /= 2;
        i++;
    }
    j = L;
    ll r = 1;
    if(j == 0){
        while(R >= r*2){
            r *= 2;
            i++;
        }
    }
    while(1){
        while((1LL<<i) * (j+1) > R and i > 0){
            i--;
            j *= 2;
        }
        ans.push_back({(1LL<<i)*j,(1LL<<i) * (j+1)});
        L = (1LL<<i) * (j+1);
        i = 0; j = 0;
        if(L >= R){
            break;
        }
        while(L%2 == 0 and L > 0){
            L /= 2;
            i++;
        }
        j = L;
    }
    int siz = (int)ans.size();
    cout << siz << endl;
    for(int i = 0; i < siz; i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}
