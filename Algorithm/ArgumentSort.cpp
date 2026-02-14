#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
    偏角ソート
*/
struct point{
    int x,y;
};
ll cross(const point &a, const point &b){
    // aベクトルとbベクトルの外積
    return (ll)a.x*b.y - (ll)a.y*b.x;
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