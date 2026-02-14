#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N;
    cin >> N;
    vector<int> A(N),visited(N,-1);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        A[i]--;
    }
    auto dfs = [&](auto self,int v)->int{
        if(visited[v] >= 0) return visited[v];

        int nv = A[v];
        if(v == nv){
            return visited[v] = v;
        }
        return visited[v] = self(self,nv);
    };
    for(int i = 0; i < N; i++){
        cout << dfs(dfs,i)+1 << " ";
    }
    cout << endl;
}
