#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        ll px1,py1,qx1,qy1;
        ll px2,py2,qx2,qy2;
        cin >> px1 >> py1 >> qx1 >> qy1;
        cin >> px2 >> py2 >> qx2 >> qy2;

        // 中心(a,b)の直線の方程式に交点があるかどうか
        // 直線が一致しているか、平行ではないか
        ll ra1 = 2*(px1-qx1);
        ll rb1 = 2*(py1-qy1);
        ll r1 = px1*px1 - qx1*qx1 + py1*py1 - qy1*qy1;
        
        ll ra2 = 2*(px2-qx2);
        ll rb2 = 2*(py2-qy2);
        ll r2 = px2*px2 - qx2*qx2 + py2*py2 - qy2*qy2;
        
        ll k1 = __gcd(ra1,__gcd(rb1,r1));
        ra1 /= k1;
        rb1 /= k1;
        r1 /= k1;
        if(ra1 < 0){
            ra1 *= -1;
            rb1 *= -1;
            r1 *= -1;
        }

        ll k2 = __gcd(ra2,__gcd(rb2,r2));
        ra2 /= k2;
        rb2 /= k2;
        r2 /= k2;
        if(ra2 < 0){
            ra2 *= -1;
            rb2 *= -1;
            r2 *= -1;
        }

        if(ra1 == ra2 and rb1 == rb2 and r1 == r2){
            cout << "Yes" << endl;
        }
        else if(ra1*rb2 == ra2*rb1){
            cout << "No" << endl;
        }
        else cout << "Yes" << endl;
    }
}
