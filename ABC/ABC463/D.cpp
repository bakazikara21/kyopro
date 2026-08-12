#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K; cin >> N >> K;
    vector<pair<int,int>> RL(N);
    for(int i = 0; i < N; i++){
        // [L,R]の区間の長さが小さいやつを選ぶとよい
        // 左端はRの最小値となる布
        // 右端はLの最大値となる布
        int l,r;
        cin >> l >> r;
        RL[i] = {r,l};
    }
    sort(RL.begin(),RL.end());
    int left = 0;
    int right = inf+1;
    int x = (right+left)/2;
    while((right-left) > 1){
        /*
            スコアをx以上にできるか
            できるなら、
            任意の連続する布の右端と左端の距離はx以上
            かつ
            K個以上の布を選択できる
        */
        int cnt = 0;
        int l,r;
        for(int i = 0; i < N; i++){
            auto [R,L] = RL[i];
            if(i == 0){
                r = R;
                cnt++;
                continue;
            }
            else{
                l = L;
                if((l-r) < x) continue;
                r = R;
                cnt++;
            }
        }
        if(cnt >= K){
            left = x;
        }
        else right = x;
        x = (right+left)/2;
    }
    if(left == 0) left--;
    cout << left << endl;
}
