#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;

    set<pair<int,int>> st;
    
    for(int i = 0; i < M; i++){
        int R,C;
        cin >> R >> C;

        if(st.count({R,C}) or st.count({R+1,C}) or st.count({R,C+1}) or st.count({R+1,C+1})){
            continue;
        }else{
            st.insert({R,C});
            st.insert({R+1,C});
            st.insert({R,C+1});
            st.insert({R+1,C+1});
        }
    }
    cout << (int)st.size()/4 << endl;
}