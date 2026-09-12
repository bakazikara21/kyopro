#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    string S; cin >> S;
    vector<int> cnt(26);
    int N = (int)S.size();
    int maxi = 0;
    for(int i = 0; i < N; i++){
        int num = S[i]-'a';
        cnt[num]++;
        maxi = max(maxi,cnt[num]);
    }
    set<char> st;
    for(int i = 0; i < 26; i++){
        if(cnt[i] == maxi){
            st.insert('a' + i);
        }
    }
    for(int i = 0; i < N; i++){
        if(!st.count(S[i])) cout << S[i];
    }
    cout << endl;
}
