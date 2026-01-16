#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int &a : A) cin >> a;
    vector<pair<int,int>> pairs(N);
    for(int i = 0; i < N; i++){
        pairs[i] = {A[i],i};
    }
    sort(pairs.begin(),pairs.end());
    vector<int> t(N,N);   // t[i]:= A[i]=A[s]なるs(i+1 <= s <= N)
    for(int i = 0 ; i < N-1; i++){
        int id1 = pairs[i].second;
        int id2 = pairs[i+1].second;
        if(pairs[i].first == pairs[i+1].first){
            t[id1] = id2;
        }
    }
    ll sum = 0;
    ll cnt = 0;
    set<int> st;
    for(int i = 0; i < N; i++){
        if(!st.count(A[i])){
            cnt++;
            st.insert(A[i]);
        }
        sum += cnt;
    }
    ll ans = sum;
    //cout << "sum = " << sum << endl;
    for(int i = 1; i < N; i++){
        sum -= (t[i-1]-(i-1));
        ans += sum;
        //cout << "sum = " << sum << endl;
    }
    cout << ans << endl;
}
