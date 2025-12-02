#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int T;
    cin >> T;

    for(int j = 0; j < T; j++){
        bool ok = true;
        ll N,H;
        cin >> N >> H;
        int time = 0;
        int minH = H;
        int maxH = H;
        for(ll i = 0; i < N; i++){
            ll t,l,u;
            cin >> t >> l >> u;

            // l <= X <= u かつ minH - t <= X <= maxH + t
            // となる最大のXをminH
            if(u < minH-(t-time) or l > maxH+(t-time)){
                ok = false;
            }
            //cout << minH << " " << maxH << endl;
            minH = max(l,minH-(t-time));
            minH = max(minH,0);
            maxH = min(u,maxH+(t-time));
            time = t;
        }
        if(ok){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
/*
1
10 36
27 37 38
30 34 54
38 20 77
45 1 36
49 38 51
52 31 58
65 43 60
71 14 42
73 36 38
85 14 29

*/
