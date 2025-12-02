#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N,M;
    cin >> N >> M;

    vector<ll> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];

    // Pから4つ以下の値を足してM以下での最大値を求める
    ll ans = 0;
    sort(P.begin(),P.end());

    // 1本投げるとき
    for(int i = 0; i < N; i++){
        if(P[i] > M) break;
        ans = P[i];
    }

    // 2本投げるとき
    vector<ll> available;     // 取りうるすべての値を保存する
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            available.push_back(P[i]+P[j]);
        }
    }
    sort(available.begin(),available.end());
    int t = upper_bound(available.begin(),available.end(),M) - available.begin() - 1;
    if(t >= 0){
        ans = max(ans,available[t]);
    }

    // 3本投げるとき
    for(int i = 0; i < N; i++){
        int t = upper_bound(available.begin(),available.end(),M-P[i]) - available.begin() - 1;
        if(t >= 0){
            ans = max(ans,available[t]+P[i]);
            //cout << ans << endl;
        }
    }

    // 4本投げるとき
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int t = upper_bound(available.begin(),available.end(),M-P[i]-P[j]) - available.begin() - 1;
            if(t >= 0){
                ans = max(ans,available[t]+P[i]+P[j]);
            }
        }
    }
    cout << ans << endl;
}