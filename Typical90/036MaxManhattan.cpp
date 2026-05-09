#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

// 絶対値が出てくる問題は、場合分け or 式変形によって絶対値を外そう。
// まさかの |a| = max(a,-a)を利用する
int main(){
    int N,Q; cin >> N >> Q;
    vector<ll> x(N),y(N);
    vector<ll> xMy(N),xPy(N);
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
        xMy[i] = x[i]-y[i];     // x-yの昇順になる
        xPy[i] = x[i]+y[i];     // x+yの昇順になる
    }
    sort(xMy.begin(),xMy.end());
    sort(xPy.begin(),xPy.end());
    for(int q = 0; q < Q; q++){
        int id; cin >> id; id--;
        ll X = x[id]; ll Y = y[id];
        ll u = X+Y; ll v = X-Y;
        /*
            |x - X| + |y - Y|
            = max(x-X,X-x) + max(y-Y,Y-y)
            = max(
                x+y - (X+Y),
                X+Y - (x+y),
                x-y - (X-Y),
                X-Y - (x-y)
            )
            = max(|x+y - (X+Y)|, |x-y - (X-Y)|)
            = max(|u1-u2|, |v1-v2|)
            と変形できるので、
            x+yの最大・最小とx-yの最大・最小がわかれば終了
        */
        ll Umx = xPy[N-1]; // 定数なので外に出せる
        ll Umn = xPy[0];
        ll U = max((Umx-u),(u-Umn));

        ll Vmx = xMy[N-1];
        ll Vmn = xMy[0];
        ll V = max((Vmx-v),(v-Vmn));

        cout << max(U,V) << endl;
    }
}