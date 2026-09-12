#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
// 余事象を考える
// Na == Nb or Nb == Nc or Nc == Naとなる連続部分文字列の個数をN(N+1)/2から引き算すればよい
int main(){
    ll N; string S; cin >> N >> S; // "A","B","C"のみからなる文字列
    vector<ll> A_B(N),B_C(N),C_A(N);   // Aの個数 - Bの個数の累積和配列: A_B
    for(int i = 0; i < N; i++){
        if(i == 0){
            A_B[i] = (S[i] == 'A') - (S[i] == 'B');
            B_C[i] = (S[i] == 'B') - (S[i] == 'C');
            C_A[i] = (S[i] == 'C') - (S[i] == 'A');
        }
        else {
            A_B[i] = (S[i] == 'A') - (S[i] == 'B') + A_B[i-1];
            B_C[i] = (S[i] == 'B') - (S[i] == 'C') + B_C[i-1];
            C_A[i] = (S[i] == 'C') - (S[i] == 'A') + C_A[i-1];
        }
    }
    ll sub = 0, add = 0;
    for(int i = 0; i < N; i++){
        if(A_B[i] == 0 or B_C[i] == 0 or C_A[i] == 0) sub++;
    }
    vector<tuple<ll,ll,ll>> sorted(N);
    for(int i = 0; i < N; i++){
        sorted[i] = {A_B[i],B_C[i],C_A[i]};
    }
    sort(sorted.begin(),sorted.end());
    for(int i = 0; i < N-1; i++){
        ll cnt = 1; // A_B(i),B_C(i),C_A(i)それぞれがA_B(i+1),B_C(i+1),C_A(i+1)と一致している個数
        auto [a,b,c] = sorted[i];
        auto [na,nb,nc] = sorted[i+1];
        while(i+1 < N and a == na and b == nb and c == nc){
            i++; cnt++;
            a = na; b = nb; c = nc;
            if(i+1 >= N) break;
            auto [nna,nnb,nnc] = sorted[i+1];
            na = nna; nb = nnb; nc = nnc;
        }
        add += (cnt-1)*cnt;
    }
    ll ans = (N+1)*N/2;
    // あとは値が等しい数を個別に nC2してansから引き算して終わり
    map<int,ll> A_Bmp;  // [key, val] = [A_B[]の値, その値の個数]
    map<int,ll> B_Cmp;
    map<int,ll> C_Amp;
    for(int i = 0; i < N; i++){
        A_Bmp[A_B[i]]++;
        B_Cmp[B_C[i]]++;
        C_Amp[C_A[i]]++;
    }
    for(auto [key,val] : A_Bmp){
        // Aの個数とBの個数が一致するような連続部分文字列の個数
        sub += (val-1)*val/2;
    }
    for(auto [key,val] : B_Cmp){
        sub += (val-1)*val/2;
    }
    for(auto [key,val] : C_Amp){
        sub += (val-1)*val/2;
    }
    cout << ans - sub + add << endl;
}
