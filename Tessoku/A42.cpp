#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 2e9; // 十分大きい値

int main(){
    int N,K;
    cin >> N >> K;
    
    vector<pair<int,int>> AB(N);
    for(int i = 0; i < N; i++){
        int A,B;
        cin >> A >> B;
        AB[i] = {A,B};
    }
    sort(AB.begin(),AB.end());
    
    int ans = 0;
    for(int a = 1; a <= 100; a++){
        for(int b = 1; b <= 100; b++){
            int cnt = 0;
            // 体力はa~a+K 気力はb~b+Kの人だけで構成する
            int ta = lower_bound(AB.begin(),AB.end(), make_pair(a, -INF))-AB.begin();
            int tak = upper_bound(AB.begin(),AB.end(), make_pair(a+K, INF))-AB.begin();
            for(int p = ta; p < tak; p++){
                int B = AB[p].second;
                if(B >= b and B <= b+K){
                    cnt++;
                }
            }
            ans = max(ans,cnt);
        }
    }
    cout << ans << endl;
}
