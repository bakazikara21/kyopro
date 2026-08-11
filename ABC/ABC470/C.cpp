#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,Q; cin >> N >> Q;
    queue<int> que;
    vector<int> A(N);
    int ans = 0;
    for(int q = 0; q < Q; q++){
        int n; cin >> n;

        if(n == 1){
            int x; cin >> x; x--;
            ans ^= A[x];
            A[x]++;
            ans ^= A[x];
            if(A[x] == 1) que.push(x);
        }
        else{
            // 最大でも合計で Q/2 回で済む
            int imax = (int)que.size();
            for(int i = 0; i < imax; i++){
                int v = que.front(); que.pop();
                ans ^= A[v];
                A[v]--;
                ans ^= A[v];
                if(A[v] > 0) que.push(v);
            }
        }
        cout << ans << endl;
    }
}
