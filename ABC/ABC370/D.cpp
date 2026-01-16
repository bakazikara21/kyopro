#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e9;

int main(){
    int H,W,Q;
    cin >> H >> W >> Q;

    vector<set<int>> rst(H+1); // 各行の{column}の集合
    vector<set<int>> cst(W+1); // 各列の{row}の集合
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            rst[i].insert(j);
            cst[j].insert(i);
        }
    }
    int ans = H*W;
    for(int q = 0; q < Q; q++){
        int R,C;
        cin >> R >> C;
        
        if(rst[R].count(C)){
            rst[R].erase(C);
            cst[C].erase(R);
            ans--;
        }
        else{
            if(cst[C].size() > 0){
                auto itr = cst[C].lower_bound(R);
                if(itr != cst[C].begin()){
                    // C列目の1~R-1行目に存在する場合
                    itr = prev(itr);
                    rst[*itr].erase(C);
                    cst[C].erase(itr);
                    ans--;

                    itr = cst[C].lower_bound(R);
                    if(itr != cst[C].end()){
                        // C列目のR+1~H行目にも存在する場合
                        rst[*itr].erase(C);
                        cst[C].erase(itr);
                        ans--;
                    }
                }
                else{
                    // C列目のR+1~H行目のみに存在する場合
                    rst[*itr].erase(C);
                    cst[C].erase(itr);
                    ans--;
                }
            }
            if(rst[R].size() > 0){
                auto itr = rst[R].lower_bound(C);
                if(itr != rst[R].begin()){
                    // R行目の1~C-1列目にも存在する場合
                    itr = prev(itr);
                    cst[*itr].erase(R);
                    rst[R].erase(itr);
                    ans--;

                    itr = rst[R].lower_bound(C);
                    if(itr != rst[R].end()){
                        // R行目のC+1~W列目にも存在する場合
                        cst[*itr].erase(R);
                        rst[R].erase(itr);
                        ans--;
                    }
                }
                else{
                    // R行目のC+1~W列目のみに存在する場合
                    cst[*itr].erase(R);
                    rst[R].erase(itr);
                    ans--;
                }
            }
        }
    }
    cout << ans << endl;
}