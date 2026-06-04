#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N; string S,T; cin >> N >> S >> T;
    /*
        000や111となる部分文字列は存在しないことが保証されている
        2^26個の部屋が存在する。7*10^7くらい。4*10^5未満が保証されている。
        現在いる文字列から、最も下位の桁から順に移動できるか確認していけばよい。

        00100->00101->00110->01001->01010->01011->01100->01101->10010->10011->10100->10101->10110->11001->11010->11011
    */
    unordered_set<string> st;
    vector<string> rooms;
    unordered_map<string,int> order;
    auto dfs = [&](auto self, string s, int zeros, int ones)->void{
        // sは0 or 1からなる現状の文字列
        int M = (int)s.size();
        if(M == N){
            if(zeros < 3 and ones < 3) st.insert(s),rooms.push_back(s);
            return;
        }
        if(zeros+1 < 3) self(self,s+'0',zeros+1,0);
        if(ones+1 < 3) self(self,s+'1',0,ones+1);
    };
    dfs(dfs,"0",1,0);
    dfs(dfs,"1",0,1);
    int M = (int)rooms.size();  // roomの文字列の全列挙は完了
    sort(rooms.begin(),rooms.end());
    for(int i = 0; i < M; i++){
        order[rooms[i]] = i;
    }
    int ans = 0;
    st.erase(S);
    while(S != T){
        int ord = inf;
        string nxt = "";
        for(int i = 0; i < N; i++){
            string s = S;
            s[i] = '0' + (1 - (s[i]-'0'));
            if(st.count(s)){
                if(ord > order[s]){
                    ord = order[s];
                    nxt = s;
                }
            }
        }
        if(nxt == ""){
            break;
        }
        S = nxt;
        st.erase(S);
        ans++;
    }
    if(S == T){
        cout << ans << endl;
    }
    else cout << -1 << endl;
}
