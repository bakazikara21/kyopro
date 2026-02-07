#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
const int inf = (int)2e5;
int main(){
    int N;
    cin >> N;
    vector<int> A(N),cnt(inf+7);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        cnt[1]++;
        cnt[A[i]+1]--;
    }
    for(int i = 1; i <= inf+6; i++){
        cnt[i+1] += cnt[i];
    }
    for(int i = 1; i <= inf+6; i++){
        cnt[i+1] += (cnt[i]/10);
        cnt[i] %= 10;
    }
    int i = inf+6;
    while(cnt[i] == 0){
        i--;
    }
    for(int j = i; j >= 1; j--){
        cout << cnt[j];
    }
    cout << endl;
}
