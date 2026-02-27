#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
/*
    区間の整数の種類の総数を求める問題
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
    vector<int> P(N);
    for(int i = 0; i < N; i++){
        cin >> P[i];
    }
    vector<tuple<int,int,int>> query(Q);
    for(int q = 0; q < Q; q++){
        int L,R;
        cin >> L >> R;
        query[q] = {R,L,q};
    }
    sort(query.begin(),query.end());
    vector<int> ans(Q),last(N+1,-1);
    int n = init(N);
    SegRSQ segtree(n);
    int now = 0;
    set<int> st;
    for(int q = 0; q < Q; q++){
        auto [R,L,id] = query[q];
        while(now < R){
            if(st.count(P[now])){
                segtree.update(last[P[now]],0);
                segtree.update(now + 1,1);
                last[P[now]] = now + 1;
            }
            else{
                st.insert(P[now]);
                last[P[now]] = now + 1;
                segtree.update(now + 1,1);
            }
            now++;
        }
        ans[id] = segtree.segSum(L,R+1,1,1,n+1);
    }
    for(int q = 0; q < Q; q++){
        cout << ans[q] << endl;
    }
}
