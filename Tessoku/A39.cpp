#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> RL(N);
    for(int i = 0; i < N; i++){
        int L,R;
        cin >> L >> R;
        RL[i] = {R,L};
    }
    sort(RL.begin(),RL.end());

    int ans = 0;
    int Rnow = 0;
    for(int i = 0; i < N; i++){
        int r = RL[i].first;
        int l = RL[i].second;
        if(Rnow <= l){
            ans++;
            Rnow = r;
        }
    }
    cout << ans << endl;
}
