#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; cin >> N;
    vector<string> S(N);
    set<pair<string,string>> st;
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        reverse(s.begin(),s.end());
        string t = s;
        reverse(s.begin(),s.end());
        if(s > t) swap(s,t);
        st.insert({s,t});
    }
    cout << st.size() << endl;
}
