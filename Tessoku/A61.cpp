#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int>> graph(N);
    for(int i = 0; i < M; i++){
        int A,B;
        cin >> A >> B;
        A--; B--;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    for(int i = 0; i < N; i++){
        cout << i+1 << ": {";
        for(int j = 0; j < (int)graph[i].size(); j++){
            if(j+1 != (int)graph[i].size()) cout << graph[i][j]+1 << ", ";
            else cout << graph[i][j]+1;
        }
        cout << "}" << endl;
    }
}
