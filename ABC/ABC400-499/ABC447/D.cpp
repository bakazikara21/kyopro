#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    string S; cin >> S;
    vector<int> cnt(3,0);
    int N = (int)S.size();
    for(int i = 0; i < N; i++){
        if(S[i] == 'A'){
            cnt[0]++;
        }
        else if(S[i] == 'B'){
            if(cnt[0] > 0){
                cnt[1]++;
                cnt[0]--;
            }
        }
        else{
            if(cnt[1] > 0){
                cnt[2]++;
                cnt[1]--;
            }
        }
    }
    cout << cnt[2] << endl;
}
