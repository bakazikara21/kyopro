#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; cin >> N >> M;
    vector<int> num(M);
    for(int i = 0; i < N; i++){
        int A,B; cin >> A >> B;
        A--; B--;
        num[A]--;
        num[B]++;
    }
    for(int i = 0; i < M; i++) cout << num[i] << endl;
}
