#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,L,R;
    cin >> N >> L >> R;
    vector<pair<int,int>> score_id;
    for(int i = 0; i < N; i++){
        int P;
        cin >> P;

        if(P >= L and P <= R){
            score_id.push_back({-P,i+1});
        }
    }
    if((int)score_id.size() == 0){
        cout << -1 << endl;
        return 0;
    }
    sort(score_id.begin(),score_id.end());
    cout << score_id[0].second << endl;
}
