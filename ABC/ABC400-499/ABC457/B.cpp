#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<vector<int>> A(N);
    for(int i = 0; i < N; i++){
        int L; cin >> L;
        for(int j = 0; j < L; j++){
            int a; cin >> a;
            A[i].push_back(a);
        }
    }
    int X,Y; cin >> X >> Y; X--; Y--;
    cout << A[X][Y] << endl;
}
