#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<int> P(N),Q(N),pos(N);
    for(int i = 0; i < N; i++) cin >> P[i];
    for(int i = 0; i < N; i++) cin >> Q[i];
    for(int i = 0; i < N; i++) pos[i] = i+1;

    int ans = 0;
    do{
        if(P < pos and pos < Q){
            ans++;
        }
    }while(next_permutation(pos.begin(),pos.end()));
    cout << ans << endl;
}
