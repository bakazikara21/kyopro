#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;
    ll sx,sy;
    cin >> sx >> sy;

    vector<int> dx = {0,0,-1,1};
    vector<int> dy = {1,-1,0,0};
    
    map<ll,set<ll>> xst;    // xに存在するyをすべて保持
    map<ll,set<ll>> yst;    // yに存在するxをすべて保持
    for(int i = 0; i < N; i++){
        ll X,Y;
        cin >> X >> Y;
        xst[X].insert(Y);
        yst[Y].insert(X);
    }
    ll x = sx;
    ll y = sy;
    ll ans = 0;
    for(int i = 0; i < M; i++){
        // M回、直進して移動する
        char D; ll C;
        cin >> D >> C;
    
        ll nx = x;
        ll ny = y;
        if(D == 'U'){
            ny += C;
            // (x,y)~(x,ny)に含まれる家をカウントして破壊する
            auto itr = xst[x].lower_bound(y);
            auto itr_end = xst[x].upper_bound(ny);
            while(itr != itr_end){
                yst[*itr].erase(x);
                itr = xst[x].erase(itr);
                ans++;
            }
        }
        if(D == 'D'){
            ny -= C;
            // (x,ny)~(x,y)に含まれる家をカウントして破壊する
            auto itr = xst[x].lower_bound(ny);
            auto itr_end = xst[x].upper_bound(y);
            while(itr != itr_end){
                yst[*itr].erase(x);
                itr = xst[x].erase(itr);
                ans++;
            }
        }
        if(D == 'L'){
            nx -= C;
            // (nx,y)~(x,y)に含まれる家をカウントして破壊する
            auto itr = yst[y].lower_bound(nx);
            auto itr_end = yst[y].upper_bound(x);
            while(itr != itr_end){
                xst[*itr].erase(y);
                itr = yst[y].erase(itr);
                ans++;
            }
        }
        if(D == 'R'){
            nx += C;
            // (x,y)~(nx,y)に含まれる家をカウントして破壊する
            auto itr = yst[y].lower_bound(x);
            auto itr_end = yst[y].upper_bound(nx);
            while(itr != itr_end){
                xst[*itr].erase(y);
                itr = yst[y].erase(itr);
                ans++;
            }
        }
        x = nx;
        y = ny;
    }
    cout << x << " " << y << " " << ans << endl;
}
