#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int N,D;
        cin >> N >> D;

        queue<pair<int,int>> que;
        for(int i = 0; i < N; i++){
            int A;
            cin >> A;
            que.push({A,i});
        }
        for(int i = 0; i < N; i++){
            int B; cin >> B;
            int egg = que.front().first;
            if(egg > B){
                que.front().first -= B;
            }
            else {
                while(egg <= B){
                    B -= egg;
                    que.pop();
                    if(!que.empty()) egg = que.front().first;
                }
                if(!que.empty() and B > 0) que.front().first -= B;
            }
            while(!que.empty() and que.front().second+D <= i){
                que.pop();
            }
        }
        int ans = 0;
        while(!que.empty()){
            ans += que.front().first;
            que.pop();
        }
        cout << ans << endl;
    }
}
