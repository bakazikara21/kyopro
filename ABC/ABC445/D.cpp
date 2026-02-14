#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int H,W,N;
    cin >> H >> W >> N;
    vector<pair<int,int>> piece(N),pos(N);
    set<pair<int,int>> stH,stW;
    for(int i = 0; i < N; i++){
        cin >> piece[i].first >> piece[i].second;
        stH.insert({piece[i].first,i});
        stW.insert({piece[i].second,i});
    }
    // まずh = H or w = Wが必ず存在する
    // -> h' = H-h or w' = W-w が必ず存在する
    // 右下から左上に向かって板チョコを割っていく
    auto dfs = [&](auto self, int h, int w, int num){
        //cout << "num = " << num << " H = " << h << " W = " << w << endl << endl;
        if(num > N) return;
        auto itrH = stH.lower_bound({h,0});
        auto itrW = stW.lower_bound({w,0});

        if(itrH != stH.end() and itrH->first == h){
            //cout << "itrH->first = " << itrH->first << " ";
            int id = itrH->second;
            int hei = piece[id].first;
            int wid = piece[id].second;
            pos[id] = {1,w-wid+1};
            stH.erase(itrH); stW.erase({wid,id});
            //cout << "hei = " << hei << " wid = " << wid << " id = " << id << endl;
            self(self,h,w-wid,num+1);
        }
        else if(itrW != stW.end() and itrW->first == w){
            //cout << "itrW->first" << itrW->first << " ";
            int id = itrW->second;
            int hei = piece[id].first;
            int wid = piece[id].second;
            pos[id] = {h-hei+1,1};
            stW.erase(itrW); stH.erase({hei,id});
            //cout << "hei = " << hei << " wid = " << wid << " id = " << id << endl;
            self(self,h-hei,w,num+1);
        }
        return;
    };
    dfs(dfs,H,W,1);
    for(int i = 0; i < N; i++){
        cout << pos[i].first << " " << pos[i].second << endl;
    }
}
