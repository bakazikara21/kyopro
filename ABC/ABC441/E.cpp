#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
(Aの個数)>(Bの個数)となる
連続する部分文字列の個数を求めよ
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
    int N;
    string S;   // A,B,Cのみからなる文字列
    cin >> N >> S;
    /*
        Aの個数-Bの個数を累積和を取って求める(presum)
        presum[0] = 0として計算すると
        S[l]~S[r]に含まれる(Aの個数-Bの個数) = presum[r+1]-presum[l]
        presum[r+1]-presum[l] > 0となる(l,r)の組の個数を求めれば良い
    */
    // presum[0]~presum[r]の値を0が7個、1が5個、-2が3個、...のように記録したとしたら、
    // -INF~presum[r+1]-1の値の個数の総和を高速に求められれば良い。
    // 区間和セグメント木 data[0]=7,data[1]=5,data[-2]=3,...,
    // 配列の中身がマイナスにならないように+Nしとけば良い
    // 2*N+1の長さの配列を持てるようにする

    int n = 2*N+1; // data[-N]->data[0], data[N]->data[2*N]
    n = init(n);
    SegRSQ segtree(n);
    vector<int> presum(N+1);    // Aの個数-Bの個数の累積和
    for(int i = 0; i < N; i++){
        presum[i+1] = presum[i] + (S[i]=='A') - (S[i]=='B');
    }
    segtree.add(N+1+presum[0],1);   // 0の個数を+1, 1-indexedだから+(N+1)する
    ll ans = 0;
    for(int i = 0; i < N; i++){
        // A[i]が左端のときの区間の個数をセグメント木で求める

        // presum[i+1]未満の値の個数を求めてansに加算する
        ans += segtree.segSum(1,N+1+presum[i+1],1,1,n+1);

        // presum[i+1]の値の個数をインクリメント
        segtree.add(N+1+presum[i+1],1);
    }
    cout << ans << endl;
}
