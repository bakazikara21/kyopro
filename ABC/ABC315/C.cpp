#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<vector<int>> flav(N);
    vector<int> mx(N,-inf);
    int ans = 0;
    for(int i = 0; i < N; i++){
        int f,s; cin >> f >> s; f--;
        flav[f].push_back(s);
        mx[f] = max(mx[f],s);
    }
    sort(mx.rbegin(),mx.rend());
    ans = max(ans,mx[0]+mx[1]);

    for(int i = 0; i < N; i++){
        int M = flav[i].size();
        if(M <= 1) continue;
        sort(flav[i].rbegin(),flav[i].rend());
        ans = max(ans,flav[i][0]+flav[i][1]/2);
    }
    cout << ans << endl;
}
