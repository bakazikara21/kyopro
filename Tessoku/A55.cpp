#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int Q;
    cin >> Q;
    set<int> st;
    for(int q = 0; q < Q; q++){
        int num,x;
        cin >> num >> x;
        if(num == 1){
            st.insert(x);
        }
        if(num == 2){
            st.erase(x);
        }
        if(num == 3){
            auto itr = st.lower_bound(x);
            if(itr != st.end()) cout << *itr << endl;
            else cout << -1 << endl;
        }
    }
}
