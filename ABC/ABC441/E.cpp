#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<ll> presum(N);
    map<ll,ll> mp;
    ll pls = 0;
    for(int i = 0; i < N; i++){
        if(i == 0){
            presum[i] = (S[i]=='A') - (S[i]=='B');
            mp[presum[i]]++;
            if(presum[i] > 0) pls++;
        }
        else{
            presum[i] = presum[i-1] + (S[i]=='A') - (S[i]=='B');
            mp[presum[i]]++;
            if(presum[i] > 0) pls++;
        }
    }
    // 区間加算して区間にある正の整数の個数を求められれば解けるのに
    ll sum = 0;
    ll ans = 0;
    //cout << "plus = " << pls << endl;
    for(int i = 0; i < N; i++){
        // 左端をS[i]として区間の正の整数の個数を求める
        ans += pls;
        mp[presum[i]]--;    // 個数をデクリメント
        if(presum[i]+sum > 0){
            pls--;
        }
        if(S[i] == 'A'){
            // 区間減少
            sum--;
            if(mp.count(-sum)){
                pls -= mp[-sum];
            }
        }
        if(S[i] == 'B'){
            // 区間増加
            sum++;
            if(mp.count(1-sum)){
                pls += mp[1-sum];
            }
        }
        //cout << "plus = " << pls << " sum = " << sum << " ans = " << ans << endl;
    }
    cout << ans << endl;
}
