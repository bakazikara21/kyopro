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
        //ll mini = L;
        //ll maxi = R;
        bool covered = false;
        while(ijoL != RL.end()){
            if(ijoL->second > R) break;

            if(ijoL->first <= R and ijoL->second >= L){
                // 完全にLからRの間に入っていたら
                ans += (ijoL->first - ijoL->second + 1);
            }else if(ijoL->first <= R){
                // R側だけ区間内のとき(高々1個)
                // 領域を分割する
                ans += (ijoL->first - L + 1);
                //mini = max(mini,ijoL->first);
               
                resv.push_back({L-1,ijoL->second});
            }else if(ijoL->second >= L){
                // L側だけ区間内のとき(高々1個)
                // 領域を分割する
                ans += (R - ijoL->second + 1);
                //maxi = min(maxi,ijoL->second);
               
                resv.push_back({ijoL->first,R+1});
            }else if(ijoL->first > R and ijoL->second < L){
                // 完全に覆われていたら
                covered = true;
            
                break;
            }
            ijoL = RL.erase(ijoL);
        }
        if(covered == false) {
            resv.push_back({R,L});
            ans -= R-L+1;
        }
        int sz = resv.size();
		for(int i=0; i < sz; i++){
			RL.insert(resv[i]);
		}
        cout << ans << endl;
    }
}
