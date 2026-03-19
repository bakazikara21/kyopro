#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double PI = acosl(-1);

struct point{
    ll x,y;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<point> pos(N);
    for(int i = 0; i < N; i++){
        cin >> pos[i].x >> pos[i].y;
    }

    long double ans = 0.0;

    for(int i = 0; i < N; i++){
        vector<long double> ang;

        for(int j = 0; j < N; j++){
            if(i == j) continue;
            ll dx = pos[j].x - pos[i].x;
            ll dy = pos[j].y - pos[i].y;
            long double a = atan2(dy, dx) * 180.0 / PI;
            if(a < 0) a += 360.0;
            ang.push_back(a);
        }

        sort(ang.begin(), ang.end());

        int M = ang.size();

        // 円環対応で2倍
        vector<long double> ang2 = ang;
        for(auto a : ang){
            ang2.push_back(a + 360.0);
        }

        for(int j = 0; j < M; j++){
            long double target = ang[j] + 180.0;

            // lower_bound
            auto it = lower_bound(ang2.begin(), ang2.end(), target);

            // 候補1
            if(it != ang2.end()){
                long double diff = abs(*it - ang[j]);
                diff = min(diff, 360.0 - diff);
                ans = max(ans, diff);
            }

            // 候補2
            if(it != ang2.begin()){
                it--;
                long double diff = abs(*it - ang[j]);
                diff = min(diff, 360.0 - diff);
                ans = max(ans, diff);
            }
        }
    }

    cout << fixed << setprecision(12) << ans << endl;
}
