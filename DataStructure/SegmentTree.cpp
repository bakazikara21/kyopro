#include <bits/stdc++.h>
using namespace std;

class SegRMQ{
    // セグメント木RMQ
    public:
        vector<int> seg;

        SegRMQ(int N) : seg(2*N){
            for(int i = 0; i < 2*N; i++){
                seg[i] = 0;
            }
        }

        void update(int pos, int x){
            seg[pos] = x;
            while(pos > 1){
                // 上層部の最大値区間を更新する
                pos /= 2;
                // seg[pos]が更新されなかったらbreakでもよいと思う
                seg[pos] = max(seg[pos*2],seg[pos*2 + 1]);
            }
        }

        int segMax(int left, int right, int pos, int first, int last){
            // [left,right)に注意する
            if(right <= first or left >= last) return -10000;
            if(left <= first and last <= right) return seg[pos];

            int mid = (first+last)/2;
            int AnswerL = segMax(left,right,pos*2    ,first,mid);
            int AnswerR = segMax(left,right,pos*2 + 1,mid,last);
            return max(AnswerL,AnswerR);
        }
};

class SegRSQ{
    // セグメント木RSQ
    public:
        vector<int> seg;

        SegRSQ(int N) : seg(2*N){
            for(int i = 0; i < 2*N; i++){
                seg[i] = 0;
            }
        }

        void update(int pos, int x){
            int dif = x-seg[pos];
            seg[pos] = x;
            while(pos > 1){
                // 上層部の最大値区間を更新する
                pos /= 2;
                // seg[pos]が更新されなかったらbreakでもよいと思う
                seg[pos] += dif;
            }
        }

        int segSum(int left, int right, int pos, int first, int last){
            // [left,right)に注意する
            if(right <= first or left >= last) return 0;
            if(left <= first and last <= right) return seg[pos];

            int mid = (first+last)/2;
            int AnswerL = segSum(left,right,pos*2    ,first,mid);
            int AnswerR = segSum(left,right,pos*2 + 1,mid,last);
            return AnswerL+AnswerR;
        }
};