#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;

    vector<int> Q(N),A(N),B(N),q(N);
    for(int i = 0; i < N; i++) cin >> Q[i];
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    int maxA = (int)1e7;
    for(int i = 0; i < N; i++){
        int AA = A[i];
        if(AA == 0){
            AA = (int)1e6;
        }
        else AA = Q[i]/AA;

        maxA = min(maxA,AA);
    }
    int ans = 0;
    for(int i = 0; i <= maxA; i++){
        // Aがi個のときのBの個数の最大値
        for(int j = 0; j < N; j++){
            q[j] = Q[j]-i*A[j];
        }
        int maxB = (int)1e7;
        for(int j = 0; j < N; j++){
            int BB = B[j];
            if(BB == 0){
                BB = (int)1e6;
            }
            else BB = q[j]/BB;

            maxB = min(maxB,BB);
        }
        ans = max(ans,i+maxB);
    }
    cout << ans << endl;
}
