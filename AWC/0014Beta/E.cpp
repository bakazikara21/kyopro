#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
/*
    ある配列に対して区間加算と区間和を求める問題
*/
class SegRSQ{
    // セグメント木RSQ 区間和
    public:
        vector<ll> seg;
        int n;

        SegRSQ(int N) : seg(2*N){
            for(int i = 0; i < 2*N; i++){
                seg[i] = 0;
            }
            n = N;
        }

        void update(int pos, ll x){
            pos += n-1; // 1-indexed
            seg[pos] = x;
            while(pos > 1){
                // 上層部の区間和を更新する
                pos /= 2;
                // seg[pos]が更新されなかったらbreakでもよいと思う
                seg[pos] = seg[pos*2] + seg[pos*2+1];
            }
        }

        void add(int pos, ll x){
            // segに差分配列を持たせると区間加算が実現できる
            // 区間加算を行うとき、加算による更新が必要
            pos += n-1; // 1-indexed
            seg[pos] += x;
            while(pos > 1){
                // 上層部の区間和を更新する
                pos /= 2;
                // seg[pos]が更新されなかったらbreakでもよいと思う
                seg[pos] = seg[pos*2] + seg[pos*2+1];
            }
        }

        ll segSum(int left, int right, int pos, int first, int last){
            // [left,right)に注意する
            if(right <= first or left >= last) return 0;
            if(left <= first and last <= right) return seg[pos];

            int mid = (first+last)/2;
            ll AnswerL = segSum(left,right,pos*2    ,first,mid);
            ll AnswerR = segSum(left,right,pos*2 + 1,mid,last);
            return AnswerL+AnswerR;
        }
};

int init(int N){
    int siz = 1;
    while(siz < N){
        siz *= 2;
    }
    return siz;
}
int main(){
    int N,Q; cin >> N >> Q;
    int n = init(N);
    SegRSQ segtree1(n),segtree2(n);
    vector<ll> C(N);
    for(int i = 0; i < N; i++){
        cin >> C[i];
        if(i > 0){
            segtree1.update(i+1,C[i]-C[i-1]);
            segtree2.update(i+1,i*(C[i]-C[i-1]));
        } 
        else{
            segtree1.update(i+1,C[i]); 
            segtree2.update(i+1,0);
        }   
    }
    for(int q = 0; q < Q; q++){
        int num; cin >> num;
        if(num == 1){
            int l,r; ll v; cin >> l >> r >> v;
            // 区間加算
            segtree1.add(l,v);
            if(r+1 <= N) segtree1.add(r+1,-v);

            segtree2.add(l,(l-1)*v);
            if(r+1 <= N) segtree2.add(r+1,-r*v);
        }
        if(num == 2){
            int l,r; cin >> l >> r;
            // 区間和
            ll sr = (r)*segtree1.segSum(1,r+1,1,1,n+1) - segtree2.segSum(1,r+1,1,1,n+1);
            ll sl = (l-1)*segtree1.segSum(1,l,1,1,n+1) - segtree2.segSum(1,l,1,1,n+1);
            cout << sr - sl << endl;
        }
    }
}
