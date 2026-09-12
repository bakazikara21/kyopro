#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    string S; cin >> S;
    int Q; cin >> Q;
    vector<tuple<int,int,char>> query(Q);
    for(int q = 0; q < Q; q++){
        int t,x; char c;
        cin >> t >> x >> c;
        x--;
        query[q] = {t,x,c};
    }
    bool big = false;
    bool small = false;
    vector<bool> used(N,false);
    for(int q = Q-1; q >= 0; q--){
        auto [t,x,c] = query[q];
        if(t == 1){
            if(big and (c-'a') >= 0 and (c-'a') <= 25){
                c ^= 32;
            }
            else if(small and (c-'A') >= 0 and (c-'A') <= 25){
                c ^= 32;
            }
            if(!used[x]){
                used[x] = true;
                S[x] = c;
            }
        }
        if(t == 2 and !big and !small){
            small = true;
            for(int i = 0; i < N; i++){
                if(used[i]) continue;
                char ch = S[i];
                if((ch-'A') >= 0 and (ch-'A') <= 25){
                    ch ^= 32;
                }
                S[i] = ch;
            }
        }
        if(t == 3 and !small and !big){
            big = true;
            for(int i = 0; i < N; i++){
                if(used[i]) continue;
                char ch = S[i];
                if((ch-'a') >= 0 and (ch-'a') <= 25){
                    ch ^= 32;
                }
                S[i] = ch;
            }
        }
    }
    cout << S << endl;
}
