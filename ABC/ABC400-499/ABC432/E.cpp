#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

class SegmentTreeRSQ{
    // セグメント木RSQ 区間和
    public:
        vector<ll> segsum;
        int n;

        SegmentTreeRSQ(int N) : segsum(2*N){
            for(int i = 0; i < 2*N; i++){
                segsum[i] = 0;
            }
            n = N;
        }

        // A[pos]の値をxに更新する
        void update(int pos, ll x){
            pos += n-1; // 1-indexed
            segsum[pos] = x;
            while(pos > 1){
                // 上層部の区間和を更新する
                pos /= 2;
                // segsum[pos]が更新されなかったらbreakでもよいと思う
                segsum[pos] = segsum[pos*2] + segsum[pos*2+1];
            }
        }

        // A[pos]の値を +x する
        void add(int pos, ll x){
            // segに差分配列を持たせると区間加算が実現できる
            // 区間加算を行うとき、加算による更新が必要
            pos += n-1; // 1-indexed
            segsum[pos] += x;
            while(pos > 1){
                // 上層部の区間和を更新する
                pos /= 2;
                // pos*2が左の子、pos*2+1が右の子に対応する
                segsum[pos] = segsum[pos*2] + segsum[pos*2+1];
            }
        }

        ll getRangeSum(int left, int right, int pos, int first, int last){
            // [left,right)に注意する
            if(right <= first or left >= last) return 0;
            if(left <= first and last <= right) return segsum[pos];

            int mid = (first+last)/2;
            ll AnswerL = getRangeSum(left,right,pos*2    ,first,mid);
            ll AnswerR = getRangeSum(left,right,pos*2 + 1,mid  ,last);
            return AnswerL+AnswerR;
        }
};

// N以上の整数で最小の2のべき乗を返す
int init(int N){
    int siz = 1;
    while(siz < N){
        siz *= 2;
    }
    return siz;
}
int main(){
    int N,Q; cin >> N >> Q;
    int n = init(500001);
    SegmentTreeRSQ segtree1(n);
    SegmentTreeRSQ segtree2(n);
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        segtree1.add(A[i]+1,1); // 個数を更新
        segtree2.add(A[i]+1,A[i]);  // 個数と値の積
    }
    for(int q = 0; q < Q; q++){
        int num; cin >> num;
        if(num == 1){
            int x,y; cin >> x >> y;
            x--;
            segtree1.add(A[x]+1,-1);
            segtree2.add(A[x]+1,-A[x]);
            A[x] = y;
            segtree1.add(A[x]+1,1);
            segtree2.add(A[x]+1,A[x]);
        }
        if(num == 2){
            ll l,r; cin >> l >> r;
            if(l >= r){
                cout << N*l << endl;
            }
            else{
                ll ans = 0;
                // A[i] > rの個数
                int bigger = N - segtree1.getRangeSum(1,r+2,1,1,n+1);
                
                // A[i] < lの個数
                int smaller = segtree1.getRangeSum(1,l+1,1,1,n+1);

                ans += r*bigger + l*smaller;
                ans += segtree2.getRangeSum(l+1,r+2,1,1,n+1);
                cout << ans << endl;
            }
        }
    }
}
