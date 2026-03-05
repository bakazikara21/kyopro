#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
/*
    FenwickTree :   
    "任意の整数は2のべき乗の和で表せる"という性質を利用する
    LSB(最下位ビット)を i&(-i) で取得できることを利用する
    rangesum[i] = (A[i]を終端とする長さ(i&(-i))の区間和)
    1-indexed

    rangesum[1] = A[1];                     // LSB = 1
    rangesum[2] = A[1] + A[2];              // LSB = 2
    rangesum[3] = A[3];                     // LSB = 1
    rangesum[4] = A[1] + A[2] + A[3] + A[4];
    rangesum[5] = A[5];                     // LSB = 1
    rangesum[6] = A[5] + A[6];
    rangesum[7] = A[7];
    .
    .
    "LSBを0にした数に更新"を000になるまで繰り返しながら、その添字に対応するrangesumの値を足していく
    A[1] + A[2] + ... + A[5] + A[6] + A[7]
    = rangesum[0111] + rangesum[0110] + rangesum[0100]; ->えぐいて
*/
class FenwickTree{
    private:
    vector<ll> rangesum;
    int n;

    public:
    FenwickTree(int N) : rangesum(N+1,0){
        n = N+1;
    }

    void add(int pos, ll x){
        /*
            現在のインデックス i に LSBを足していく (i += i & -i) ことで、
            更新すべき親ノードへと順に移動できます。->えぐいて
        */ 
        while(pos < n){
            rangesum[pos] += x;
            pos += (pos&(-pos));
        }
    }

    // A[left]~A[right]の区間和を返す
    ll getRangeSum(int left, int right){
        // leftもrightも1-indexedとする
        ll sumR = 0, sumL = 0;
        while(right > 0){
            sumR += rangesum[right];
            right -= (right&(-right));
        }
        left--;
        while(left > 0){
            sumL += rangesum[left];
            left -= (left&(-left));
        }
        return sumR-sumL;
    }
};