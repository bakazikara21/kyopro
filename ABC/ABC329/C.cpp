#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// set<string> st;を使うとMLEになる直大トラップ
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> maxi(26);

    ll ans = 0;
    for(int i = 0; i < N; i++){
        int len = 1;
        int kind = S[i]-'a';
        maxi[kind] = max(maxi[kind],len);
        while(i+1 < N and S[i] == S[i+1]){
            len++;
            maxi[kind] = max(maxi[kind],len);
            i++;
        }
    }
    for(int i = 0; i < 26; i++){
        ans += maxi[i];
    }
    cout << ans << endl;
}
