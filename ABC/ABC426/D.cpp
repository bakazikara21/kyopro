#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const int inf = 1e9;
const ll mod = 1e9 + 7;
const int den = 1e5;

int main(){
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        int N;
        string S;
        cin >> N >> S;
        // Nlog(N)ぐらいで終わらせる
        // すべての文字を同じ文字にする
        // 全部1にするか全部0にするか、min()をとってもよさそう
        // 左右のコストの和が最小になるように先頭or末尾を決める
        // 目的の文字と一緒の文字を変更するとcost += 2
        // 別の文字なら cost += 1;

        int OneLeft = 0, OneRight = 0;
        int ZeroLeft = 0, ZeroRight = 0;

        int oneLast = -1, zeroLast = -1;
        vector<int> OneR(N+1),OneL(N+1),ZeroR(N+1),ZeroL(N+1);
        for(int i = N; i >= 1; i--){
            // iのときの右側のコストを事前に計算する
            if(S[i-1]=='1'){
                ZeroR[i-1] = ZeroR[i] + 1;
                if(oneLast == -1) oneLast = i;
                if(zeroLast != -1) ZeroR[i-1] += (zeroLast - i)*2;
                zeroLast = -1;

                OneR[i-1] = OneR[i];
            }else{
                OneR[i-1] = OneR[i] + 1;
                if(zeroLast == -1) zeroLast = i;
                if(oneLast != -1) OneR[i-1] += (oneLast - i)*2;
                oneLast = -1;

                ZeroR[i-1] = ZeroR[i];
            }
        }
        oneLast = -1, zeroLast = -1;
        for(int i = 0; i < N; i++){
            // iのときの左側のコストを事前に計算する
            if(S[i]=='1'){
                ZeroL[i+1] = ZeroL[i] + 1;
                if(oneLast == -1) oneLast = i;
                if(zeroLast != -1) ZeroL[i+1] += (i - zeroLast)*2;
                zeroLast = -1;

                OneL[i+1] = OneL[i];
            }else{
                OneL[i+1] = OneL[i] + 1;
                if(zeroLast == -1) zeroLast = i;
                if(oneLast != -1) OneL[i+1] += (i - oneLast)*2;
                oneLast = -1;

                ZeroL[i+1] = ZeroL[i];
            }
        }
        int cost = inf;
        for(int i = 0; i <= N; i++){
            // i-1番目以下のコスト　+ i番目以降のコスト
            
            cost = min(cost, OneL[i] + OneR[i]);
            cost = min(cost, ZeroL[i] + ZeroR[i]);
        }
        cout << cost << endl;
    }
}
