#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    偏角ソートの練習問題らしいです。
*/
struct point{
    ll x,y;
};
ll cross(const point &a, const point &b){
    // aベクトルとbベクトルの外積
    return a.x*b.y - a.y*b.x;
}
bool cmp(const point &a, const point &b){
    int ah = (a.y < 0 or (a.y == 0 and a.x < 0));   // 上半分なら0
    int bh = (b.y < 0 or (b.y == 0 and b.x < 0));   // 下半分なら1
    if(ah != bh) return ah < bh;    // 下半分のほうが偏角は大きい
    return cross(a,b) > 0;  // aとbの外積が正ならbの偏角のほうが大きい
}
void argument_sort(vector<point> &points){
    sort(points.begin(),points.end(),cmp);
}
int main(){
    int N,Q;
    cin >> N >> Q;
    vector<point> pos(N),points(N);
    vector<vector<double>> shogen(5);
    for(int i = 0; i < N; i++){
        // N体のモンスターの座標
        ll X,Y;
        cin >> X >> Y;
        pos[i].x = X; 
        pos[i].y = Y;
        points[i] = pos[i];
        //cout << "pos[" << i << "] = " << pos[i].first << " " << pos[i].second << endl;
    }
    argument_sort(pos);

    for(int q = 0; q < Q; q++){
        int A,B;
        cin >> A >> B;
        A--; B--;
        // points[A]~points[B]まで回転して消滅させる
        int na = lower_bound(pos.begin(),pos.end(),points[A],cmp)-pos.begin();
        int nb = lower_bound(pos.begin(),pos.end(),points[B],cmp)-pos.begin();
        if(nb > na){
            // x軸をまたいで回転するとき
            na = upper_bound(pos.begin(),pos.end(),points[A],cmp)-pos.begin();
            cout << (N-nb)+na << endl;
        }
        else{
            // またがないで時計回りに回転するとき
            na = upper_bound(pos.begin(),pos.end(),points[A],cmp)-pos.begin();
            cout << (na-nb) << endl;
        }
    }
}
