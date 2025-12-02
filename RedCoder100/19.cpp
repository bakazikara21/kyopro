#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int d;  // 環状線の全長
    cin >> d;
    
    int n; // 店舗の個数
    cin >> n;

    int m;  // 注文の個数
    cin >> m;

    vector<int> S(n+1); // 店舗の位置
    S[0] = 0;
    S[n] = d;
    for(int i = 1; i < n; i++){
        cin >> S[i];
        //cout << S[i] << endl;
    }
    sort(S.begin(),S.end());
    ll ans = 0;
    for(int i = 0; i < m; i++){
        int k;  // 宅配先の場所
        cin >> k;

        // kに最も近いS[i]を求めて ans += abs(k-S[i]);
        int left = 0, right = n;
        int med = (right+left)/2;
        while((right-left) > 1){
            if(S[med] > k){
                right = med;
            }else{
                left = med;
            }
            med = (right+left)/2;
        }
        ans += min(abs(k-S[right]),abs(k-S[left]));
        //cout << abs(k-S[right]) << " " << abs(k-S[left]) << endl;
    }
    cout << ans << endl;
}