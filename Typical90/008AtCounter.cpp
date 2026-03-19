#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)1000000007; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    string S; cin >> S;
    map<char,int> mp;
    mp['a'] = 0;
    mp['t'] = 1;
    mp['c'] = 2;
    mp['o'] = 3;
    mp['d'] = 4;
    mp['e'] = 5;
    mp['r'] = 6;
    vector<int> cnt(7,0);
    for(int i = 0; i < N; i++){
        if(mp.count(S[i])){
            int num = mp[S[i]];
            if(num > 0 and cnt[num-1]>0){
                cnt[num] += cnt[num-1];
            }
            else if(num == 0) cnt[num]++;
            cnt[num]%=mod;
        }
    }
    cout << cnt[6]%mod << endl;
}
