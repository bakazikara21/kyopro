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

        ll getValue(int pos){
            pos += n-1;
            return segmax[pos];
        }
};
int init(int N){
    int ret = 1;
    while(ret < N){
        ret *= 2;
    }
    return ret;
}
int main(){
    int W,N; cin >> W >> N;
    // vector<ll> dp(W+1,0);   // dp[w] := ちょうどwグラムで出せる最大の価値
    int n = init(W+1);
    SegmentTreeRMQ tree(n);
    for(int i = 0; i < N; i++){
        int L,R; cin >> L >> R;
        ll V; cin >> V;

        for(int w = W; w >= 0; w--){
            // 前半の配列の要素によって後半の要素の値が決まるので後ろから計算するべき

            if(w-L < 0) break;
            // for(int k = L; k <= R; k++){
            //     dp[w-R]~dp[w-L]の最大値dp[max]
            //     dp[w] = max(dp[w],dp[max]+V);
            //     dp[w] = max(dp[w],dp[w-k]+V);
            // }

            // 1点更新の区間和
            int l = max(0,w-R);
            ll mx = tree.getRangeMax(l+1,w-L+2);
            if(tree.getValue(w+1) < mx+V and (mx >= 1 or l == 0)) tree.update(w+1,mx+V);
        }
    }
    ll ans = tree.getValue(W+1);
    if(ans == 0) ans = -1;
    cout << ans << endl;
}