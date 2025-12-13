#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<vector<int>> graph(N);
    for(int i = 1; i < N; i++){
        cin >> A[i];
        A[i]--;
        graph[A[i]].push_back(i);
    }
    // dfsで行けるだろ
    vector<int> ans(N);
    function<void(int)> dfs = [&](int v){
        int sum = 0;
        for(int nv : graph[v]){
            dfs(nv);
            sum += ans[nv]+1;
        }
        ans[v] = sum;
    };
    dfs(0);
    for(int i = 0; i < N; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
