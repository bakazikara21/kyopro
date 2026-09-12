#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<vector<int>> graph(N);
    queue<int> que;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(A[i] != -1){
            graph[A[i]-1].push_back(i);
        }
        else{
            que.push(i);
        }
    }
    while(!que.empty()){
        int p = que.front(); que.pop();
        cout << p+1 << " ";

        for(int np : graph[p]){
            que.push(np);
        }
    }
    cout << endl;
}
