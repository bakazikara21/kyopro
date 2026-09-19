#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

/*
    セグメント木は完全二分木を1次元配列で管理する
*/
class SegmentTreeRMQ{
    // セグメント木RMQ 区間最大・最小
    private:
    vector<ll> segmax;
    vector<ll> segmin;
    int n;
    
    public:
        SegmentTreeRMQ(int N):segmax(2*N),segmin(2*N){
            for(int i = 0; i < 2*N; i++){
                segmax[i] = 0;
                segmin[i] = 0;
            }
            n = N;
        }

        // A[pos]の値をxに更新する
        void update(int pos, ll x){
            pos += n-1; // 1-indexed
            segmax[pos] = x;
            segmin[pos] = x;
            while(pos > 1){
                // 上層部の最大値区間を更新する
                pos /= 2;
                // segmax[pos]が更新されなかったらbreakでもよいと思う
                segmax[pos] = max(segmax[pos*2],segmax[pos*2 + 1]);
                segmin[pos] = min(segmin[pos*2],segmin[pos*2 + 1]);
            }
        }

        // A[pos]の値を +x する
        void add(int pos, ll x){
            pos += n-1; // 1-indexed
            segmax[pos] += x;
            segmin[pos] += x;
            while(pos > 1){
                // 上層部の区間の最大値と最小値を更新する
                pos /= 2;
                // pos*2が左の子、pos*2+1が右の子に対応する
                segmax[pos] = max(segmax[pos*2],segmax[pos*2 + 1]);
                segmin[pos] = min(segmin[pos*2],segmin[pos*2 + 1]);
            }
        }

        // [left,right)の区間の最大値を返す
        ll getRangeMax(int left, int right, int pos = 1, int first = 1, int last = -1){
            if(last < 0) last = n+1;
            // [left,right)に注意する
            if(right <= first or left >= last) return (ll)-1e18;
            if(left <= first and last <= right) return segmax[pos];

            int mid = (first+last)/2;
            ll AnswerL = getRangeMax(left,right,pos*2    ,first,mid);
            ll AnswerR = getRangeMax(left,right,pos*2 + 1,mid,last);
            return max(AnswerL,AnswerR);
        }

        // [left,right)の区間の最小値を返す
        ll getRangeMin(int left, int right, int pos = 1, int first = 1, int last = -1){
            if(last < 0) last = n+1;
            // [left,right)に注意する
            if(right <= first or left >= last) return (ll)1e18;
            if(left <= first and last <= right) return segmin[pos];

            int mid = (first+last)/2;
            ll AnswerL = getRangeMin(left,right,pos*2    ,first,mid);
            ll AnswerR = getRangeMin(left,right,pos*2 + 1,mid  ,last);
            return min(AnswerL,AnswerR);
        }

        // 最初の要素からの区間の最大値がX以上となる最小の1-indexを返す
        int lower_boundMax(ll X, int pos = 1){
            if(pos == 1 and segmax[1] < X) return -1;
            if(pos >= n) return pos-n+1;

            if(segmax[pos*2] >= X){
                // 左の子がX以上なら左側に答えがある
                return lower_boundMax(X,pos*2);
            }
            else{
                // そうでないなら右側に答えがある
                return lower_boundMax(X,pos*2+1);
            }
        }

        // 最初の要素からの区間の最小値がX以下となる最小の1-indexを返す
        int lower_boundMin(ll X, int pos = 1){
            if(pos == 1 and segmin[1] > X) return -1;
            if(pos >= n) return pos-n+1;

            if(segmin[pos*2] <= X){
                // 左の子がX以下なら左側に答えがある
                return lower_boundMin(X,pos*2);
            }
            else{
                // そうでないなら右側に答えがある
                return lower_boundMin(X,pos*2+1);
            }
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
    int N,M; cin >> N >> M;
    int n = init(N);
    SegmentTreeRMQ segtree(n);
    vector<int> pos(N+1);
    for(int i = 0; i < N; i++){
        int P; cin >> P;
        pos[P] = i;
        segtree.update(i+1,P);
    }

    for(int i = 0; i < M; i++){
        int L,R; cin >> L >> R;
        int mx = segtree.getRangeMax(L,R+1);
        int mn = segtree.getRangeMin(L,R+1);

        int mxId = pos[mx];
        int mnId = pos[mn];

        swap(pos[mx],pos[mn]);
        segtree.update(mxId+1,mn);
        segtree.update(mnId+1,mx);
    }

    for(int i = 0; i < N; i++){
        cout << segtree.getRangeMax(i+1,i+2) << " ";
    }
    cout << endl;
}
