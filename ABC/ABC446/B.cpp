#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M;
    cin >> N >> M;
    set<int> st;
    for(int i = 0; i < N; i++){
        int L;
        cin >> L;

        int bin = 0;
        bool flag = false;
        for(int j = 0; j < L; j++){
            int drink;
            cin >> drink;
            if(flag) continue;
            if(!st.count(drink)){
                bin = drink;
                st.insert(drink);
                flag = true;
            }
        }
        cout << bin << endl;
    }
}
