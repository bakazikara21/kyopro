#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N;
    cin >> N;
    vector<int> cnt(N);
    for (int i = 0; i < N; i++)
    {
        int C;
        cin >> C;
        C--;
        cnt[C]++;
    }
    int mx = 0;
    for (int i = 0; i < N; i++)
        mx = max(mx, cnt[i]);
    cout << N - mx << endl;
}
