#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 一番きつかったかも
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
            // 1-indexed 加算更新
            pos += (n-1);
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
    int N,M;
    cin >> N >> M;
    vector<ll> A(N),D(N);   // Aの差分配列D
    int n = init(N);
    SegRSQ seg(n);  // 区間和セグメント木
    for(int i = 0 ; i < N; i++){
        cin >> A[i];
        if(i == 0) D[i] = A[i];
        else D[i] = A[i]-A[i-1];
        seg.update(i+1,D[i]);   // 1-indexed
    }
    // A[i] = D[0] + D[1] + D[2] +...+ D[i]; を利用する
    // A[i] = seg.segSum(1,i+1);
    for(int i = 0; i < M; i++){
        int B;
        cin >> B;

        ll ball = seg.segSum(1,B+2,1,1,n+1);    // ballの個数A[B]を入手

        // A[B] = 0にしたい->D[B] -= A[B]; D[B+1] += A[B];
        seg.update(B+1,-ball);    // D[B] -= A[B];
        if(B+2 <= N) seg.update(B+2,ball);   // D[B+1] += A[B];

        ll all = ball/N;    // 全体に+all
        seg.update(1,all); // 全体にallを加算->D[0] += all;

        ll mod = ball % N;  // あまり
        if(B+2+mod <= N){
            seg.update(B+2,+1); // D[B+1] += 1;

            if(B+2+mod <= N) seg.update(B+2+mod,-1);    // D[B+1+mod] -= 1;
        }
        else{
            if(B+2 <= N) seg.update(B+2,+1);

            ll mmod = (mod-(N-1-B)) + 1;
            seg.update(1,1);

            seg.update(mmod,-1);
        }
    }
    for(int i = 0; i < N; i++){
        A[i] = seg.segSum(1,i+2,1,1,n+1);
        cout << A[i] << " ";
    }
    cout << endl;
}
