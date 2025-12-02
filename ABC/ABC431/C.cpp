#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M,K;
    cin >> N >> M >> K;

    vector<ll> H(N),B(M);
    for(int i = 0; i < N; i++) cin >> H[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    sort(H.begin(),H.end());
    sort(B.begin(),B.end());

    int b = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        int head = H[i];
        while(head > B[b]){
            b++;
            if(b >= M){
                break;
            }
        }
        if(b < M and head <= B[b]){
            cnt++;
            b++;
        }
        if(cnt >= K){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}