#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        int N;
        cin >> N;
        vector<ll> W(N),P(N),wpp(N);
        ll sumP = 0;
        for(int i = 0; i < N; i++){
            cin >> W[i] >> P[i];
            sumP += P[i];
            wpp[i] = W[i]+P[i];
        }
        sort(wpp.begin(),wpp.end());
        int ans = 0;
        for(int i = 0; i < N; i++){
            if(sumP - wpp[i] >= 0){
                sumP -= wpp[i];
                ans++;
            }else{
                break;
            }
        }
        cout << ans << endl;
    }

}