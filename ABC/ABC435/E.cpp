#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,Q;
    cin >> N >> Q;
    
    set<pair<ll,ll>> RL;
    ll ans = N;
    for(int q = 0; q < Q; q++){
        ll L,R;
        cin >> L >> R;

        auto ijoL = RL.lower_bound({L,-1});
        vector<pair<int,int>> resv;
        // L以上の区間を全探索
        ll mini = L;
        ll maxi = R;
        while(ijoL != RL.end()){
            if(ijoL->second > R) break;

            if(ijoL->first <= R and ijoL->second >= L){
                // 完全にLからRの間に入っていたら
            }else if(ijoL->first <= R){
                // R側だけ区間内のとき
                ans += (ijoL->first - ijoL->second + 1);
                mini = min(mini,ijoL->second);
               
                resv.push_back({R,ijoL->second});
            }else if(ijoL->second >= L){
                // L側だけ区間内のとき
                ans += (ijoL->first - ijoL->second + 1);
                maxi = max(maxi,ijoL->first);
               
                resv.push_back({ijoL->first,L});
            }else if(ijoL->first > R and ijoL->second < L){
                // 完全に覆われていたら
                maxi = 1;
                mini = 0;
                continue;
            }
            ijoL = RL.erase(ijoL);
        }
        int sz =resv.size();
		for(int i=0;i<sz;i++){
			RL.insert(resv[i]);
		}
        ans -= maxi-mini+1;
        cout << ans << endl;
    }
}