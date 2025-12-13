#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    int correct = 0;
    for(int i = 0; i < N; i++){
        cin >> P[i];
        P[i]--;
        if(P[i] == i) correct++;
    }
    // すでに合っている個数= correct
    ll ans = N-correct;
    for(int i = 0; i < N; i++){
        if(P[i] == i) continue;
        //P[i]番目の値とP[P[i]]
        if(P[P[P[i]]] > i) ans++;
    }
    cout << ans << endl;
}