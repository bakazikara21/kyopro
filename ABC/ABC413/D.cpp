#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int N; cin >> N;
        vector<ll> A(N);
        vector<pair<ll,ll>> absolute(N);
        for(int i = 0; i < N; i++){
            // + - + - + ... or
            // - + - + - ... or
            // + + + + + ... or
            // - - - - - ...である必要がある
            cin >> A[i];
            absolute[i] = {abs(A[i]),i};
        }
        if(N == 2){
            cout << "Yes" << endl;
            continue;
        }
        vector<ll> B(N);
        for(int i = 0; i < N; i++){
            B[i] = abs(A[i]);
        }
        sort(B.begin(),B.end());
        bool all = true;
        for(int i = 0; i < N-1; i++){
            //  |r| == 1
            if(B[i] != B[i+1]) all = false;
        }
        if(all){
            // 全ての値が絶対値に関して等しいとき
            int pls = 0, mis = 0;
            for(int i = 0; i < N; i++){
                if(A[i] < 0) mis++;
                else pls++;
            }
            //cout << "plus = " << pls << " minus = " << mis << endl;
            if(pls == 0 or mis == 0 or abs(pls-mis) <= 1) ;
            else all = false;
        }
        if(all){
            cout << "Yes" << endl;
            continue;
        }
        sort(absolute.begin(),absolute.end());
        bool flag = false;
        for(int i = 1; i < N-1; i++){
            // 左右の符号が等しければok
            ll leftID = absolute[i-1].second;
            ll rightID = absolute[i+1].second;
            if(A[leftID]*A[rightID] < 0) flag = true;
        }
        if(flag){
            cout << "No" << endl;
            continue;
        }
        bool ok = true;
        for(int i = 1; i < N-1; i++){
            // |r| ≠ 1
            if(B[i]*B[i] != B[i-1]*B[i+1]) ok = false;
        }
        if(all or ok){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}