#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<int> cnt(N);
    vector<pair<int,int>> f(N);
    for(int i = 0; i < 3*N; i++){
        int a; cin >> a; a--;
        cnt[a]++;
        if(cnt[a] == 2){
            f[a].first = i + 1;
            f[a].second = a + 1;
        }
    }
    sort(f.begin(),f.end());
    for(auto [i,a] : f){
        cout << a << " ";
    }
    cout << endl;
}
