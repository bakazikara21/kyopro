#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M; cin >> N >> M;
    map<pair<int,int>,int> mp;
    vector<vector<pair<int,int>>> leftLong(N+1);  // 左に伸びてる区間
    vector<vector<pair<int,int>>> rightLong(N+1); // 右に伸びてる区間
    for(int i = 0; i < M; i++){
        int L,R; cin >> L >> R; mp[{L,R}]++;
        leftLong[R].push_back({L,i});   // Lまで伸びている
        rightLong[L].push_back({R,i});  // indexも明示する
    }
    for(int i = 1; i <= N; i++){
        int L = (int)leftLong[i].size();
        int R = (int)rightLong[i].size();
        if(L >= 1) sort(leftLong[i].begin(),leftLong[i].end());
        if(R >= 1) sort(rightLong[i].begin(),rightLong[i].end());
    }
    // 同一の布を使わないようにすれば解ける。
    // S->Tに行ける布があるとき、S <= S' <= T' <= Tなる相異なる布S',T'が存在すればYes
    int Q; cin >> Q;
    for(int q = 0; q < Q; q++){
        int S,T; cin >> S >> T;

        int tSize = (int)leftLong[T].size();
        // Sから右に最も伸びているやつ(<= T)
        int s = upper_bound(rightLong[S].begin(),rightLong[S].end(),make_pair(T,M+1))-rightLong[S].begin()-1;

        // Tから左に伸びているやつ(>= S)
        int t = lower_bound(leftLong[T].begin(),leftLong[T].end(),make_pair(S,-1))-leftLong[T].begin();

        if(s < 0 or t >= tSize){
            // 希望なし
            cout << "No" << endl;
            continue;
        }
        // cout << "S -> " << rightLong[S][s] << " : T -> " << leftLong[T][t] << endl;
        auto [r,idr] = rightLong[S][s];
        auto [l,idl] = leftLong[T][t];
        // S -> Tに行ける布が1枚あれば、(S,T)内の布でもYesになる
        if(idr == idl){
            if(r == T and l == S){
                // S -> Tに行けるとき、
                bool ok = false;
                if(mp[{S,T}] >= 2) ok = true;
                for(int i = S+1; i <= T; i++){
                    if(ok) break;
                    if((int)rightLong[i].size() > 0 and rightLong[i][0].first <= T){
                        ok = true;
                        break;
                    }
                }
                if((int)rightLong[S].size() > 0 and rightLong[S][0].first < T){
                    ok = true;
                }
                if(ok){
                    cout << "Yes" << endl;
                    continue;
                }
            }
            // 同じ布を使ってしまっているとき
            if(s > 0){
                s--;
                if(rightLong[S][s] >= leftLong[T][t]){
                    cout << "Yes" << endl;
                    continue;
                }
                s++;
            }
            if(t+1 < tSize){
                t++;
                if(rightLong[S][s] >= leftLong[T][t]){
                    cout << "Yes" << endl;
                    continue;
                }
                t--;
            }
            cout << "No" << endl;
        }
        else if(rightLong[S][s] >= leftLong[T][t]){
                    cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}
