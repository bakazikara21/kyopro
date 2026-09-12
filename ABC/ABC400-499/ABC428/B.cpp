#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const int inf = 1e9;
const ll mod = 1e9 + 7;

int main(){
    int N,K;
    cin >> N >> K;
    string S;
    cin >> S;

    set<string> se;
    for(int i = 0; i <= N-K; i++){
        string s;
        for(int j = i; j < i+K; j++){
            s.push_back(S[j]);
        }
        se.insert(s);
    }
    int maxi = 0;
    vector<string> ans;
    for(string s : se){
        int cnt = 0;
        for(int i = 0; i <= N-K; i++){
            string ns;
            for(int j = i; j < i+K; j++){
                ns.push_back(S[j]);
            }
            if(s == ns){
                cnt++;
            }
        }
        if(cnt > maxi){
            maxi = cnt;
        }
    }
    for(string s : se){
        int cnt = 0;
        for(int i = 0; i <= N-K; i++){
            string ns;
            for(int j = i; j < i+K; j++){
                ns.push_back(S[j]);
            }
            if(s == ns){
                cnt++;
            }
        }
        if(cnt == maxi){
            ans.push_back(s);
        }
    }

    // 見つけ終わったら
    sort(ans.begin(),ans.end());
    cout << maxi << endl;
    for(string s : ans){
        cout << s << " ";
    }
    cout << endl;
}