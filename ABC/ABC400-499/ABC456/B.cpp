#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N = 3;
    int dice = 6;
   
    vector<int> cnt4(N);
    vector<int> cnt5(N);
    vector<int> cnt6(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < dice; j++){
            int a; cin >> a;
            if(a == 4) cnt4[i]++;
            if(a == 5) cnt5[i]++;
            if(a == 6) cnt6[i]++;
        }
    }
    int cnt = 0;
    cnt += cnt4[0]*cnt5[1]*cnt6[2];
    cnt += cnt4[0]*cnt5[2]*cnt6[1];
    cnt += cnt4[1]*cnt5[0]*cnt6[2];
    cnt += cnt4[1]*cnt5[2]*cnt6[0];
    cnt += cnt4[2]*cnt5[0]*cnt6[1];
    cnt += cnt4[2]*cnt5[1]*cnt6[0];
    cout << fixed << setprecision(15);
    cout << cnt / 216.0 << endl;
}
