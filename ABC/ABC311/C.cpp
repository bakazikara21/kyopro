#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<vector<int>> graph(N);
    for(int i = 0; i < N; i++){
        int a; cin >> a; a--;
        graph[i].push_back(a);
    }
    vector<bool> used(N,false);
    int end = -1;
    vector<int> path;
    auto dfs = [&](auto self, int v)->bool{
        used[v] = true;
        for(int nv : graph[v]){
            if(used[nv]){
                // nv -> vのパスを求めればよい。
                end = nv;
                path.push_back(v+1);
                return true;
            }
            else if(self(self,nv)){
                path.push_back(v+1);
                if(end == v){
                    end = -1;
                    return false;
                }
                else return true;
            }
        }
        used[v] = false;
        return false;
    };
    dfs(dfs,0);
    reverse(path.begin(),path.end());
    cout << path.size() << endl;
    for(int v : path) cout << v << " ";
    cout << endl;
}
