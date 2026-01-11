#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;

class SegRMaxQ{
    // セグメント木RMQ 区間最大
    public:
        vector<ll> seg;
        int n;

        SegRMaxQ(int N) : seg(2*N){
            for(int i = 0; i < 2*N; i++){
                seg[i] = 0;
            }
            n = N;
        }

        void update(int pos, ll x){
            pos += n-1; // 1-indexed
            seg[pos] = x;
            while(pos > 1){
                // 上層部の最大値区間を更新する
                pos /= 2;
                // seg[pos]が更新されなかったらbreakでもよいと思う
                seg[pos] = max(seg[pos*2],seg[pos*2 + 1]);
            }
        }

        ll segMax(int left, int right, int pos, int first, int last){
            // [left,right)に注意する
            if(right <= first or left >= last) return (ll)-1e18;
            if(left <= first and last <= right) return seg[pos];

            int mid = (first+last)/2;
            ll AnswerL = segMax(left,right,pos*2    ,first,mid);
            ll AnswerR = segMax(left,right,pos*2 + 1,mid,last);
            return max(AnswerL,AnswerR);
        }
};

class SegRMinQ{
    // セグメント木RMQ 区間最小
    public:
        vector<ll> seg;
        int n;

        SegRMinQ(int N) : seg(2*N){
            for(int i = 0; i < 2*N; i++){
                seg[i] = 0;
            }
            n = N;
        }

        void update(int pos, ll x){
            pos += n-1; // 1-indexed
            seg[pos] = x;
            while(pos > 1){
                // 上層部の最大値区間を更新する
                pos /= 2;
                // seg[pos]が更新されなかったらbreakでもよいと思う
                seg[pos] = min(seg[pos*2],seg[pos*2 + 1]);
            }
        }

        ll segMin(int left, int right, int pos, int first, int last){
            // [left,right)に注意する
            if(right <= first or left >= last) return (ll)1e18;
            if(left <= first and last <= right) return seg[pos];

            int mid = (first+last)/2;
            ll AnswerL = segMin(left,right,pos*2    ,first,mid);
            ll AnswerR = segMin(left,right,pos*2 + 1,mid,last);
            return min(AnswerL,AnswerR);
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
    int N,K;
    cin >> N >> K;
    vector<int> P(N);
    vector<pair<int,int>> Q(N);
    for(int i = 0; i < N; i++){
        cin >> P[i];
        Q[i] = {P[i],i};
    } 
    sort(Q.begin(),Q.end());

    for(int i = 0; i < N; i++){
        // Q[j] := (P[i] = j) なる i と定義する 
        swap(Q[i].first,Q[i].second);
        //cout << Q[i].first << " ";
    }
    //cout << endl;
    // Q[i].firstに関するRMQで最大-最小を求められる
    int n = init(N);
    SegRMaxQ segma(n);
    SegRMinQ segmi(n);
    for(int i = 0; i < N; i++){
        // 1-indexed
        segma.update(i+1,Q[i].first);
        segmi.update(i+1,Q[i].first);
    }
    ll ans = INF;
    for(int i = 0; i <= N-K; i++){
        ans = min(ans,segma.segMax(1+i,1+i+K,1,1,n+1)-segmi.segMin(1+i,1+i+K,1,1,n+1));
    }
    cout << ans << endl;
}
