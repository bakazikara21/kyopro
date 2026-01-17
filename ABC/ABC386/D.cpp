#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
/*
    (X,Y)に黒マスがあるならば
    1 <= i <= X, 1 <= j <= Y
    の長方形に白マスが含まれてはならない

    全体をx座標に関して昇順にする
    ->前から順に調べていく
    ->白マスならばy座標の最小値を記録する
    ->黒マスならば白マスのy座標の最小値より大きいかどうか調べる
*/
int main(){
    ll N,M;
    cin >> N >> M;

    // Black はmaxだけ持っておけばよい
    vector<pair<ll,ll>> Black;

    // White はminだけ持っておけばよい
    set<pair<ll,ll>> WhiteRC;
    set<pair<ll,ll>> WhiteCR;

    vector<tuple<ll,ll,char>> BW(M);
    for(int i = 0; i < M; i++){
        ll X,Y;
        char C;
        cin >> X >> Y >> C;

        BW[i] = {X,Y,C};
    }
    // 全体をx座標に関して昇順にする
    sort(BW.begin(),BW.end());
    ll minYW = INF;
    for(int i = 0; i < M; i++){
        auto [x,y,colar] = BW[i];
        if(colar == 'W'){
            minYW = min(minYW,y);
        } 
        else if(minYW <= y){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
