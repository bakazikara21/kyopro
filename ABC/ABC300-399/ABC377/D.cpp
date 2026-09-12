#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
厳しい
rを固定して、条件を満たすlの最小値d[r]をd[1]から順に求める
d[R] = max(d[R],L+1);
d[r] = max(d[r],d[r-1]);
*/
int main(){
    int N,M;
    cin >> N >> M;
    vector<int> d(M+1,1);
    for(int i = 0; i < N; i++){
        int L,R;
        cin >> L >> R;
        d[R] = max(d[R],L+1);   // Rに対する最大のLを求める
    }
    for(int i = 1; i <= M; i++){
        // i = Rとなる区間が存在しないならばd[i] = d[i-1]
        d[i] = max(d[i],d[i-1]);
    }
    ll sum = 0;
    for(int r = 1; r <= M; r++){
        sum += r-d[r]+1;
    }
    cout << sum << endl;
}
