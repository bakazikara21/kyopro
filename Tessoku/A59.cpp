#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// セグメント木RSQ
void query1(int pos, int x, vector<int> &seg){
    int dif = x-seg[pos];
    seg[pos] = x;
    while(pos > 1){
        // 上層部の最大値区間を更新する
        pos /= 2;
        // seg[pos]が更新されなかったらbreakでもよいと思う
        seg[pos] += dif;
    }
}

int query2(int left, int right, vector<int> &seg, int pos, int first, int last){
    // [left,right)に注意する
    if(right <= first or left >= last) return 0;
    if(left <= first and last <= right) return seg[pos];

    int mid = (first+last)/2;
    int AnswerL = query2(left,right,seg,pos*2,first,mid);
    int AnswerR = query2(left,right,seg,pos*2 + 1,mid,last);
    return AnswerL+AnswerR;
}
int main(){
    int N,Q;
    cin >> N >> Q;

    int two = 1;
    while(1){
        if(two/2 < N and N <= two){
            N = two;
            break;
        }
        two *= 2;
        if(two > 4*N) break;
    }
    vector<int> seg(2*N,0);
    for(int q = 0; q < Q; q++){
        int num;
        cin >> num;

        if(num == 1){
            int pos,x;
            cin >> pos >> x;

            pos = pos+N-1;
            query1(pos,x,seg);
        }
        if(num == 2){
            int l,r;
            cin >> l >> r;

            cout << query2(l,r,seg,1, 1, N+1) << endl;
        }
    }
}
