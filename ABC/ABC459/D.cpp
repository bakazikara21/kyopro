#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int T; cin >> T;

    for(int t = 0; t < T; t++){
        string S; cin >> S;
        vector<int> num(26);
        int N = (int)S.size();
        for(int i = 0; i < N; i++){
            num[S[i]-'a']++;
        }
        vector<pair<int,char>> vec(26);
        for(int i = 0; i < 26; i++){
            vec[i] = {num[i],'a'+i};
        }
        sort(vec.rbegin(),vec.rend());
        priority_queue<pair<int,char>> pq;
        deque<pair<char,int>> deq;
        for(int i = 0; i < 26; i++){
            auto [n,ch] = vec[i];
            if(n == 0) continue;
            pq.push(vec[i]);
        }
        string T = "";
        auto [mx,mxc] = pq.top(); pq.pop();
        while(1){
            T += mxc;
            mx--;

            if(pq.empty()){
                for(int i = 0; i < mx; i++){
                    T += mxc;
                }
                break;
            }
            auto pr = pq.top(); pq.pop();
            if(mx > 0) pq.push({mx,mxc});
            mx = pr.first;
            mxc = pr.second;
        }
        bool ok = true;
        for(int i = 0; i < N-1; i++){
            if(T[i] == T[i+1]){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "Yes" << endl;
            cout << T << endl;
        }
        else cout << "No" << endl;
    }
}
