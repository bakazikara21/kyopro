#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

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

        ll getRangeMax(int left, int right, int pos, int first, int last){
            // [left,right)に注意する
            if(right <= first or left >= last) return (ll)-1e18;
            if(left <= first and last <= right) return segmax[pos];

            int mid = (first+last)/2;
            ll AnswerL = getRangeMax(left,right,pos*2    ,first,mid);
            ll AnswerR = getRangeMax(left,right,pos*2 + 1,mid,last);
            return max(AnswerL,AnswerR);
        }
        ll getRangeMin(int left, int right, int pos, int first, int last){
            // [left,right)に注意する
            if(right <= first or left >= last) return (ll)1e18;
            if(left <= first and last <= right) return segmin[pos];

            int mid = (first+last)/2;
            ll AnswerL = getRangeMin(left,right,pos*2    ,first,mid);
            ll AnswerR = getRangeMin(left,right,pos*2 + 1,mid  ,last);
            return min(AnswerL,AnswerR);
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
    vector<ll> W(N),C(M);
    int n = init(M);
    SegmentTreeRMQ segtree(n);
    for(int i = 0; i < N; i++) cin >> W[i];
    for(int i = 0; i < M; i++){
        cin >> C[i];
        segtree.update(i+1,C[i]);
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        /*
            求めるスペースを二分探索で求める
            セグメント木を使って1..xの区間の最大値がW[i]以上ならxを縮める
            求めるスペースが決まったら、そいつの値を0に変更する
        */
        
        int left = 0, right = M+1;
        int x = (right+left)/2; // 1-indexed
        while((right-left) > 1){
            int maxi = segtree.getRangeMax(1,x+1,1,1,n+1);
            if(maxi >= W[i]){
                // xをもう少し小さくできる
                right = x;
            }
            else left = x;
            x = (right+left)/2;
        }
        if(right != M+1){
            segtree.update(right,0);
            ans++;
        }
    }
    cout << ans << endl;
}
