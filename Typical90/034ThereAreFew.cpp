#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K; cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    // 最後にその整数が出現したindexを管理しつつ、
    // 今読み込んでいる整数たちをqueueで管理する
    // 整数はK種類以下のまま尺取り
    int cnt = 0;
    int r = 0;
    queue<int> que;
    map<int,int> id;
    int mx = 0;
    for(int l = 0; l < N; l++){
        r = max(l,r);
        while(r < N and cnt <= K){
            if(id.count(A[r]) and id[A[r]] >= l) ;
            else if(cnt == K){
                mx = max(mx,r-l);
                break;
            }
            else cnt++;
            que.push(A[r]);
            id[A[r]] = r;
            mx = max(mx,r-l+1);
            r++;
        }
        int num = que.front(); que.pop();
        if(id[num] == l) cnt--;
    }
    cout << mx << endl;
}